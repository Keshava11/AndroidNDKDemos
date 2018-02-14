package com.ravi.androidndkdemos;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.text.Html;
import android.widget.TextView;

public class NDKDemosActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ndk_demos);

        // Get the required constants calling native method on keys
        final TextView stringsConstTxv = findViewById(R.id.string_constants_txv);
        final TextView intsConstTxv = findViewById(R.id.integer_constants_txv);

        final StringBuilder buffer = new StringBuilder();

        buffer.append("<b>STRING CONSTANTS : </b>").append("<br/>");
        buffer.append(getMyStrings("base_url")).append("<br/>");
        buffer.append(getMyStrings("user_email")).append("<br/><br/>");
        buffer.append(getMyStrings("wrong_key"));

        stringsConstTxv.setText(Html.fromHtml(buffer.toString()));

        // Clear buffer
        buffer.setLength(0);

        buffer.append("<b>INTEGER CONSTANTS : </b>").append("<br/>");
        buffer.append(getMyInts("db_version")).append("<br/>");
        buffer.append(getMyInts("nrc_length")).append("<br/><br/>");
        buffer.append(getMyInts("wrong_key"));

        intsConstTxv.setText(Html.fromHtml(buffer.toString()));
    }


    /**
     * A native method that is implemented by the 'native-lib' native library that
     * returns strings constants saved in native code
     *
     * @param iKeyName key names
     * @return String constants
     */
    public native String getMyStrings(String iKeyName);

    /**
     * A native method that is implemented by the 'native-lib' native library that
     * returns integer constants saved in native code
     *
     * @param iKeyName key names
     * @return integer constants
     */
    public native int getMyInts(String iKeyName);
}
