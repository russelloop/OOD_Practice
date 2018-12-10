package com.example.dashwood.sensor;
import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import java.util.List;

public class DeviseActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_devise);

        final TextView tx1 = (TextView)findViewById(R.id.TextView01);

        SensorManager sm = (SensorManager) getSystemService(Context.SENSOR_SERVICE);

        List<Sensor> allSensors = sm.getSensorList(Sensor.TYPE_ALL);

        tx1.setText("经检测该手机有" + allSensors.size() + "个传感器，分别是：\n");

        for (Sensor s : allSensors){

            String tempString = "\n" + "  设备名称：" + s.getName() + "\n" + "  设备版本：" + s.getVersion() + "\n" + "  供应商：" + s.getVendor() + "\n\n";

            switch ( (s.getType())){
                case Sensor.TYPE_ACCELEROMETER:
                    tx1.setText((tx1.getText().toString() + s.getType() + " 加速度传感器 (Accelerometer)" + tempString));
                    break;
                case Sensor.TYPE_GYROSCOPE:
                    tx1.setText((tx1.getText().toString() + s.getType() + " 陀螺仪传感器 (Gyroscope)" + tempString));
                    break;
                case Sensor.TYPE_LIGHT:
                    tx1.setText((tx1.getText().toString() + s.getType() + " 光纤传感器 (light)" + tempString));
                    break;
                case Sensor.TYPE_MAGNETIC_FIELD:
                    tx1.setText((tx1.getText().toString() + s.getType() + " 磁场传感器 (Magnetic Field)" + tempString));
                    break;
                case Sensor.TYPE_ORIENTATION:
                    tx1.setText((tx1.getText().toString() + s.getType() + " 方向传感器 (Orientation)" + tempString));
                    break;
                case Sensor.TYPE_PRESSURE:
                    tx1.setText((tx1.getText().toString() + s.getType() + " 压力传感器 (Pressure)" + tempString));
                    break;
                case Sensor.TYPE_PROXIMITY:
                    tx1.setText((tx1.getText().toString() + s.getType() + " 距离传感器 (Proximity)" + tempString));
                    break;
                case Sensor.TYPE_AMBIENT_TEMPERATURE:
                    tx1.setText((tx1.getText().toString() + s.getType() + " 温度传感器 (Temperature)" + tempString));
                    break;
                default:
                    tx1.setText((tx1.getText().toString() + s.getType() + " 未知传感器 (Unknown)" + tempString));
                    break;
            }
        }
    }
}

