package com.example.dashwood.sensor;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    private static final String EXTRA_MESSAGE = "com.example.dashwood.sensor.MESSAGE";;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void sendDeviseMessage(View view) {
        Intent intent1 = new Intent(this, DeviseActivity.class);
        startActivity(intent1);
    }

    public void sendLightMessage(View view) {
        Intent intent2 = new Intent(this, ShineActivity.class);
        startActivity(intent2);
    }

    public void sendGPSMessage(View view) {
        Intent intent3 = new Intent(this, GpsActivity.class);
        startActivity(intent3);
    }
}
