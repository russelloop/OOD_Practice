package com.example.dashwood.sensor;

import android.app.Activity;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.widget.TextView;


public class ShineActivity extends Activity implements SensorEventListener {

    private SensorManager sensor;
    private TextView text;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_shine);

        sensor = (SensorManager)getSystemService(SENSOR_SERVICE);
        text = (TextView)findViewById(R.id.TextView02);
    }


    @Override
    protected  void onPause(){
        sensor.unregisterListener(this);
        super.onPause();
    }

    @Override
    protected void onResume(){
        sensor.registerListener(this, sensor.getDefaultSensor(Sensor.TYPE_LIGHT), SensorManager.SENSOR_DELAY_GAME);
        super.onResume();
    }

    @Override
    protected  void onStop(){
        sensor.unregisterListener(this);
        super.onStop();
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        float[] values = event.values;
        int sensorType = event.sensor.TYPE_LIGHT;
        if (sensorType == Sensor.TYPE_LIGHT){
            text.setText(String.valueOf(values[0]));
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }
}
