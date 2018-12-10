package com.example.dashwood.sensor;

import android.Manifest;
import android.content.Context;
import android.content.pm.PackageManager;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.location.LocationProvider;
import android.os.Build;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class GpsActivity extends AppCompatActivity {
    private String[] permissions={Manifest.permission.ACCESS_FINE_LOCATION};
    final public static int REQUEST_CODE_ACCESS_FINE_LOCATION = 123;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_gps);

        LocationManager locationManager;
        String serviceName = Context.LOCATION_SERVICE;
        locationManager = (LocationManager) getSystemService(serviceName);
        Criteria criteria = new Criteria();
        criteria.setAccuracy(Criteria.ACCURACY_FINE);
        criteria.setAltitudeRequired(false);
        criteria.setBearingRequired(false);
        criteria.setCostAllowed(true);
        criteria.setPowerRequirement(Criteria.POWER_LOW);
        String provider = locationManager.getBestProvider(criteria, true);
        checkPermission();
        Location location = locationManager.getLastKnownLocation(provider);
        updateWithNewLocation(location);
        locationManager.requestLocationUpdates(provider, 2000, 10, locationListener);
    }


    private void updateWithNewLocation(Location location){
        String latLongString;
        TextView myLocationText;
        myLocationText = (TextView)findViewById(R.id.TextView03);
        myLocationText.setText("测试");
        if (location != null){
            double lat = location.getAltitude();
            double lng = location.getLongitude();
            latLongString = "纬度:" + lat + "\n经度:" + lng;
        }
        else{
            latLongString = "获取地理信息失败";
        }
        myLocationText.setText("当前坐标位置是:\n" + latLongString);
    }

    private final LocationListener locationListener = new LocationListener() {
        @Override
        public void onLocationChanged(Location location) {
            updateWithNewLocation(location);
        }

        @Override
        public void onStatusChanged(String provider, int status, Bundle extras) {

        }

        @Override
        public void onProviderEnabled(String provider) {

        }

        @Override
        public void onProviderDisabled(String provider) {
            updateWithNewLocation(null);
        }
    };

    private void checkPermission(){
        //check the permission when sdk >= 6.0
        if (Build.VERSION.SDK_INT >= 23){
            int i = ContextCompat.checkSelfPermission(this, permissions[0]);
            // Granted = accept dinied = no
            if (i != PackageManager.PERMISSION_GRANTED){
                ActivityCompat.requestPermissions(this, permissions, REQUEST_CODE_ACCESS_FINE_LOCATION);
            }else{
                //pass
            }
        }else{
            //pass
        }
    }
}
