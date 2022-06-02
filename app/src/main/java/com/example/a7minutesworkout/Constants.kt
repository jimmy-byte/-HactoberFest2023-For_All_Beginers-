package com.example.a7minutesworkout

object Constants {
    fun defaultExerciseList(): ArrayList<ExerciseModel>{
        val exerciseList=ArrayList<ExerciseModel>()
        val jumpingJacks=ExerciseModel(1,
            "Jumping Jacks",
        R.drawable.ic_jumping_jacks,
            false,
            false
        )
        exerciseList.add(jumpingJacks)
        val wallSit=ExerciseModel(2,
            "Wall Sit",
            R.drawable.ic_wall_sit,
            false,
            false
        )
        exerciseList.add(wallSit)
        val pushUp=ExerciseModel(3,
            "Push Up",
            R.drawable.ic_push_up,
            false,
            false
        )
        exerciseList.add(pushUp)
        val abdominalcrunch=ExerciseModel(4,
            "Abdominal Crunch",
            R.drawable.ic_abdominal_crunch,
            false,
            false
        )
        exerciseList.add(abdominalcrunch)
        val setUpOnChair=ExerciseModel(5,
            " Set Up On Chair",
            R.drawable.ic_step_up_onto_chair,
            false,
            false
        )
        exerciseList.add(setUpOnChair)
        val squat=ExerciseModel(6,
            "Squat",
            R.drawable.ic_squat,
            false,
            false
        )
        exerciseList.add(squat)
        val tricepDipOnChair=ExerciseModel(7,
            " Ticep Dip On Chair",
            R.drawable.ic_triceps_dip_on_chair,
            false,
            false
        )
        exerciseList.add(tricepDipOnChair)
        val plank =ExerciseModel(8,
            "Plank",
            R.drawable.ic_plank,
            false,
            false
        )
        exerciseList.add(plank)
        val highKneesRunningInPlace=ExerciseModel(9,
            "High Knees Running In Place",
            R.drawable.ic_high_knees_running_in_place,
            false,
            false
        )
        exerciseList.add(highKneesRunningInPlace)
        val lunges=ExerciseModel(10,
            "lunges",
            R.drawable.ic_lunge,
            false,
            false
        )
        exerciseList.add(lunges)
        val pushUpAndRotation=ExerciseModel(11,
            "Push Up And 5 Rotation",
            R.drawable.ic_push_up_and_rotation,
            false,
            false
        )
        exerciseList.add(pushUpAndRotation)
        val sidesPlank=ExerciseModel(12,
            "Sides Plank",
            R.drawable.ic_side_plank,
            false,
            false
        )
        exerciseList.add(sidesPlank)






        return exerciseList
    }
}