package com.gab.test.core_ui_sample;

import android.app.Activity;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.concurrent.Executor;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;


public class PressMe extends Activity {

    static final String LOG_TAG = "Log MainActivity";

    private static final int MY_CORE_POOL_SIZE = 10;
    private static final int MY_MAXIMUM_POOL_SIZE = MY_CORE_POOL_SIZE * 2 + 1;
    private static final int MY_KEEP_ALIVE = 1;
    public static final Executor MY_THREAD_POOL_EXECUTOR =
            new ThreadPoolExecutor( MY_CORE_POOL_SIZE,
                    MY_MAXIMUM_POOL_SIZE,
                    MY_KEEP_ALIVE,
                    TimeUnit.SECONDS,
                    new LinkedBlockingQueue<Runnable>(128),
                    new ThreadFactory() {
                        private final AtomicInteger mCount = new AtomicInteger(1);

                        public Thread newThread(Runnable r) {
                            return new Thread(r, "AsyncTask #" + mCount.getAndIncrement());
                        }
                    });

    private Button addContact;
    private Button recalculate;
    private TextView nmbContactsTV;
    private ListView contactLV;
    private ArrayAdapter<String> sAdapter;
    public ArrayList<String> data;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // wait incoming contacts
        new AsyncTask<Void, Void, Void>() {
            @Override
            protected Void doInBackground(Void... params) {
                Core.startWaitingContacts();
                return null;
            }
        }.executeOnExecutor(MY_THREAD_POOL_EXECUTOR);


        setContentView(R.layout.activity_press_me);

        Log.i(LOG_TAG, "nmb of threads " + String.valueOf(Runtime.getRuntime().availableProcessors()));

        addContact = (Button) findViewById( R.id.addContactBtn );
        addContact.setOnClickListener( new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.i(LOG_TAG, "button " + getString(R.string.addContactBtn) + " was pressed");
                //new addContactHandler(data, sAdapter).executeOnExecutor(MY_THREAD_POOL_EXECUTOR);
                new AsyncTask<Void, Void, String>() {
                    @Override
                    protected String doInBackground(Void... params) {
                        return Core.AddContact("some contact");
                    }

                    @Override
                    protected void onPostExecute(String result) {
                        data.add( result );
                        nmbContactsTV.setText(String.valueOf(data.size()));
                        sAdapter.notifyDataSetChanged();
                    }
                }.executeOnExecutor(MY_THREAD_POOL_EXECUTOR);
            }
        });

        recalculate = (Button) findViewById( R.id.recalculateBtn);
        recalculate.setOnClickListener( new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.i(LOG_TAG, "button " + getString(R.string.RecalculateBtn) + " was pressed");
                new AsyncTask<Void, Void, Integer>() {
                    @Override
                    protected Integer doInBackground(Void... params) {
                        return Core.GetNumberOfContacts();
                    }

                    @Override
                    protected void onPostExecute(Integer result) {
                        nmbContactsTV.setText( result.toString() );
                    }
                }.executeOnExecutor(MY_THREAD_POOL_EXECUTOR);
            }
        });

        nmbContactsTV = (TextView) findViewById(R.id.nmbContactsTV);

        contactLV = (ListView) findViewById(R.id.contactsLV);

        data = new ArrayList<String>();
        sAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, data);

        contactLV.setAdapter(sAdapter);
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.press_me, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}