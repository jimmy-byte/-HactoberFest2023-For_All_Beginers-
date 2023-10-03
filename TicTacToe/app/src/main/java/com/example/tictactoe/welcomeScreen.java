package com.example.tictactoe;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class welcomeScreen extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_welcome_screen);
        Intent goGame = new Intent(welcomeScreen.this,MainActivity.class);
        Button btn = findViewById(R.id.btnStart);
        btn.setOnClickListener(view -> {
            startActivity(goGame);
        });
    }
}