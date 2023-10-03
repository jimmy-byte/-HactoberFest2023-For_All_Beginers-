package com.example.tictactoe;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    int result = 0;
    int count = 0;
    int checkWin = 0;
    String b1, b2, b3, b4, b5, b6, b7, b8, b9;
    Button btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn1 = findViewById(R.id.btn1);
        btn2 = findViewById(R.id.btn2);
        btn3 = findViewById(R.id.btn3);
        btn4 = findViewById(R.id.btn4);
        btn5 = findViewById(R.id.btn5);
        btn6 = findViewById(R.id.btn6);
        btn7 = findViewById(R.id.btn7);
        btn8 = findViewById(R.id.btn8);
        btn9 = findViewById(R.id.btn9);
    }
    public void click(View v) {
        count++;
        Button button = (Button) v;
        if(button.getText().toString().equals("") && checkWin!=1) {
            if (result == 0) {
                button.setText("X");
                result = 1;
            } else {
                button.setText("O");
                result = 0;
            }

            b1 = btn1.getText().toString();
            b2 = btn2.getText().toString();
            b3 = btn3.getText().toString();
            b4 = btn4.getText().toString();
            b5 = btn5.getText().toString();
            b6 = btn6.getText().toString();
            b7 = btn7.getText().toString();
            b8 = btn8.getText().toString();
            b9 = btn9.getText().toString();

            if (count > 4) {

                if (b1.equals(b2) && b2.equals(b3) && !b1.equals("")) {
                    displayToast("Winner: "+b1,0);
                    btn1.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn2.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn3.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    checkWin = 1;
                } else if (b4.equals(b5) && b5.equals(b6) && !b4.equals("")) {
                    displayToast("Winner: "+b4,0);
                    btn4.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn5.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn6.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    checkWin = 1;
                } else if (b7.equals(b8) && b8.equals(b9) && !b7.equals("")) {
                    displayToast("Winner: "+b7,0);
                    btn7.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn8.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn9.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    checkWin = 1;
                } else if (b1.equals(b4) && b4.equals(b7) && !b1.equals("")) {
                    displayToast("Winner: "+b1,0);
                    btn1.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn4.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn7.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    checkWin = 1;
                } else if (b2.equals(b5) && b5.equals(b8) && !b2.equals("")) {
                    displayToast("Winner: "+b2,0);
                    btn2.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn5.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn8.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    checkWin = 1;
                } else if (b3.equals(b6) && b6.equals(b9) && !b3.equals("")) {
                    displayToast("Winner: "+b3,0);
                    btn3.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn6.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn9.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    checkWin = 1;
                } else if (b1.equals(b5) && b5.equals(b9) && !b1.equals("")) {
                    displayToast("Winner: "+b5,0);
                    btn1.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn5.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn9.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    checkWin = 1;
                } else if (b3.equals(b5) && b5.equals(b7) && !b3.equals("")) {
                    displayToast("Winner: "+b3,0);
                    btn3.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn5.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    btn7.setBackgroundColor(getResources().getColor(R.color.green,getTheme()));
                    checkWin = 1;
                } else if (count == 9) {
                    displayToast("Match Draw",1);
                    btn1.setBackgroundColor(getResources().getColor(R.color.red,getTheme()));
                    btn2.setBackgroundColor(getResources().getColor(R.color.red,getTheme()));
                    btn3.setBackgroundColor(getResources().getColor(R.color.red,getTheme()));
                    btn4.setBackgroundColor(getResources().getColor(R.color.red,getTheme()));
                    btn5.setBackgroundColor(getResources().getColor(R.color.red,getTheme()));
                    btn6.setBackgroundColor(getResources().getColor(R.color.red,getTheme()));
                    btn7.setBackgroundColor(getResources().getColor(R.color.red,getTheme()));
                    btn8.setBackgroundColor(getResources().getColor(R.color.red,getTheme()));
                    btn9.setBackgroundColor(getResources().getColor(R.color.red,getTheme()));
                }
            }
        }
    }

    public void displayToast(String msg, int flag){
        Toast toast = new Toast(this);
        View view = getLayoutInflater().inflate(R.layout.toast_layout,(ViewGroup) findViewById(R.id.l_layout));
        ImageView status_img = view.findViewById(R.id.status_img);
        TextView status = view.findViewById(R.id.status);
        toast.setView(view);
        if(flag==0){
            status_img.setImageResource(R.drawable.win_image);
        }
        else {
            status_img.setImageResource(R.drawable.draw_image);
        }
        toast.setDuration(Toast.LENGTH_LONG);
        status.setText(msg);
        toast.setGravity(Gravity.BOTTOM,0,350);
        toast.show();
    }

    public void reStart(View view) {
        btn1.setText("");
        btn2.setText("");
        btn3.setText("");
        btn4.setText("");
        btn5.setText("");
        btn6.setText("");
        btn7.setText("");
        btn8.setText("");
        btn9.setText("");
        btn1.setBackgroundColor(getResources().getColor(R.color.white,getTheme()));
        btn2.setBackgroundColor(getResources().getColor(R.color.white,getTheme()));
        btn3.setBackgroundColor(getResources().getColor(R.color.white,getTheme()));
        btn4.setBackgroundColor(getResources().getColor(R.color.white,getTheme()));
        btn5.setBackgroundColor(getResources().getColor(R.color.white,getTheme()));
        btn6.setBackgroundColor(getResources().getColor(R.color.white,getTheme()));
        btn7.setBackgroundColor(getResources().getColor(R.color.white,getTheme()));
        btn8.setBackgroundColor(getResources().getColor(R.color.white,getTheme()));
        btn9.setBackgroundColor(getResources().getColor(R.color.white,getTheme()));
        result=0;
        count=0;
        checkWin=0;
    }
}