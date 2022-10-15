package com.example.a7minutesworkout

import android.app.Dialog
import android.content.Intent
import android.media.MediaPlayer
import android.net.Uri
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.CountDownTimer
import android.speech.tts.TextToSpeech
import android.util.Log
import android.view.View
import android.widget.Toast
import androidx.recyclerview.widget.LinearLayoutManager
import com.example.a7minutesworkout.databinding.ActivityExerciseBinding
import com.example.a7minutesworkout.databinding.DialogCustomBackConfirmationButtonBinding
import java.util.*
import kotlin.collections.ArrayList

class ExerciseActivity : AppCompatActivity(), TextToSpeech.OnInitListener {
    private var binding: ActivityExerciseBinding?=null
    private var resttimer:CountDownTimer?=null
    private var restProgress=0
    private var totalTime=10

    private var exerciseTimer:CountDownTimer?=null
    private var exerciseProgress=0

    private var exerciseList:ArrayList<ExerciseModel>?=null
    private var currentExercisePosition=-1
    private var exerciseTiming=30

    private var tts: TextToSpeech? = null
    private var player: MediaPlayer? = null

    private var exerciseAdapter: ExerciseStatusAdapter? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityExerciseBinding.inflate(layoutInflater)
        setContentView(binding?.root)
        setSupportActionBar(binding?.toolBarExercise)

        if (supportActionBar != null) {
            supportActionBar?.setDisplayHomeAsUpEnabled(true)
        }
        exerciseList = Constants.defaultExerciseList()
        binding?.toolBarExercise?.setOnClickListener {
            customDialogForBackButton()
        }
        tts = TextToSpeech(this, this, "")
        setupRestView()
        setupExerciseStatusRecyclerView()
    }
        override fun onBackPressed() {
            customDialogForBackButton()
            super.onBackPressed()

    }
    private  fun customDialogForBackButton(){
        val customDialog= Dialog(this)
        val dialogBinding = DialogCustomBackConfirmationButtonBinding.inflate(layoutInflater)
        customDialog.setContentView(dialogBinding.root)
        customDialog.setCanceledOnTouchOutside(false)
        dialogBinding.btnYes.setOnClickListener {
            this@ExerciseActivity.finish()
            customDialog.dismiss() // Dialog will be dismissed
        }
        dialogBinding.btnNo.setOnClickListener {
            customDialog.dismiss()
        }
        customDialog.show()
        }


    private fun setupExerciseStatusRecyclerView() {


        binding?.rvExerciseStatus?.layoutManager =
            LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, false)


        exerciseAdapter = ExerciseStatusAdapter(exerciseList!!)


        binding?.rvExerciseStatus?.adapter = exerciseAdapter
    }
    private fun setupRestView(){
        try {
            val soundURI =
                Uri.parse("android.resource://com.example.a7minutesworkout/" + R.raw.app_src_main_res_raw_press_start)
            player = MediaPlayer.create(applicationContext, soundURI)
            player?.isLooping = false
            player?.start()
        } catch (e: Exception) {
            e.printStackTrace()
        }
        binding?.flRestView?.visibility = View.VISIBLE
        binding?.tvTitle?.visibility = View.VISIBLE
        binding?.upcomingLabel?.visibility = View.VISIBLE
        binding?.tvUpcomingExerciseName?.visibility = View.VISIBLE
        binding?.tvExerciseName?.visibility = View.INVISIBLE
        binding?.flExerciseView?.visibility = View.INVISIBLE
        binding?.ivImage?.visibility = View.INVISIBLE
        if(resttimer!=null){
            resttimer?.cancel()
            restProgress=0
        }
        binding?.tvUpcomingExerciseName?.text = exerciseList!![currentExercisePosition + 1].getName()
        setRestProgressBar()
    }
    private fun setupExerciseView(){
        binding?.flRestView?.visibility = View.INVISIBLE
        binding?.tvTitle?.visibility = View.INVISIBLE
        binding?.tvUpcomingExerciseName?.visibility = View.INVISIBLE
        binding?.upcomingLabel?.visibility = View.INVISIBLE
        binding?.tvExerciseName?.visibility = View.VISIBLE
        binding?.flExerciseView?.visibility = View.VISIBLE
        binding?.ivImage?.visibility = View.VISIBLE
       /* binding?.progressBar?.visibility= View.INVISIBLE
        binding?.tvTitle?.text="Exercise Name"
        binding?.flExerciseView?.visibility=View.VISIBLE*/

        if(exerciseTimer!=null){
            exerciseTimer?.cancel()
            exerciseProgress=0
        }
        speakOut(exerciseList!![currentExercisePosition].getName())
        binding?.ivImage?.setImageResource(exerciseList!![currentExercisePosition].getImage())
        binding?.tvExerciseName?.text = exerciseList!![currentExercisePosition].getName()
        setExerciseProgressBar()
    }
    private fun setExerciseProgressBar(){
        binding?.progressBarExercise?.progress=exerciseProgress
        exerciseTimer=object: CountDownTimer(3000,1000) {
            override fun onTick(millisUntilFinished: Long) {
                exerciseProgress++
                binding?.progressBarExercise?.progress = exerciseTiming- exerciseProgress
                binding?.tvTimerExercise?.text = (exerciseTiming- exerciseProgress).toString()


            }

            override fun onFinish() {

                if (currentExercisePosition < exerciseList?.size!! - 1) {
                    exerciseList!![currentExercisePosition].setIsSelected(false)
                    exerciseList!![currentExercisePosition].setIsCompleted(true)
                    exerciseAdapter!!.notifyDataSetChanged()
                    setupRestView()
                } else {

                    finish()
                    val intent = Intent(this@ExerciseActivity,Finish::class.java)
                    startActivity(intent)
                   /* Toast.makeText(
                        this@ExerciseActivity,
                        "Congratulations! You have completed the 7 minutes workout.",
                        Toast.LENGTH_SHORT
                    ).show()*/

                }
            }
        }.start()
    }


    private fun setRestProgressBar(){
            binding?.progressBar?.progress=restProgress
            resttimer=object: CountDownTimer(1000,1000){
                override fun onTick(millisUntilFinished: Long) {
                    restProgress++
                    binding?.progressBar?.progress=totalTime-restProgress
                    binding?.tvTimer?.text=(totalTime-restProgress).toString()


                }

                override fun onFinish() {
                    currentExercisePosition++
                    exerciseList!![currentExercisePosition].setIsSelected(true)
                    exerciseAdapter!!.notifyDataSetChanged()
                    setupExerciseView()
                    Toast.makeText(this@ExerciseActivity,
                        "Here now we will start the exercise",
                    Toast.LENGTH_SHORT).show()
                }
            }.start()
        }

    override fun onDestroy() {

        if(resttimer!=null){
            resttimer?.cancel()
            restProgress=0
    }
        if (tts != null) {
            tts!!.stop()
            tts!!.shutdown()
        }
        if(player != null){
            player!!.stop()
        }
        super.onDestroy()

        binding=null
    }
    override fun onInit(status: Int) {
        if (status == TextToSpeech.SUCCESS) {
            // set US English as language for tts
            val result = tts?.setLanguage(Locale.US)

            if (result == TextToSpeech.LANG_MISSING_DATA || result == TextToSpeech.LANG_NOT_SUPPORTED) {
                Log.e("TTS", "The Language specified is not supported!")
            }

        } else {
            Log.e("TTS", "Initialization Failed!")
        }
    }
    private fun speakOut(text: String) {
        tts!!.speak(text, TextToSpeech.QUEUE_FLUSH, null, "")
    }


    }