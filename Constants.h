// Constants.h: constants used in this project

// Timer IDs
const unsigned int ID_TIMER_VIEW(1);

// EMG
const int INIT_CHANNEL(1);
const double INIT_SENS(3);
const int INIT_SAMP_PERIOD(30);
// Bayesian filter
const double INIT_BAYES_THRESH(0.02);
const double INIT_BAYES_MAXV(3);
const double INIT_BAYES_SWITCH(0);
const double INIT_BAYES_DRIFT(1);
// Vibration
const int INIT_VIB_COM(7);
const double INIT_VIB_BAY_MAX0(0.05);
const double INIT_VIB_BAY_MIN100(1);
const double INIT_VIB_MEAN_MVC(1);
const double INIT_VIB_MEAN_MAX0(0.05);
const double INIT_VIB_MEAN_MIN100(1);
const int VIB_DRIVE_MEAN(0);
const int VIB_DRIVE_BAYES(1);
// View modes
const int VIEW_BF(0);
const int VIEW_CC_PRACTICE(1);
const int VIEW_CC_STUDY1(2);
const int VIEW_ROBOT_PRACTICE(3);
const int VIEW_ROBOT_STUDY1(4);
const int VIEW_SPEECH_STUDY1(5);
// Cursor control 
const int CC_1D_1DOF(0);
const int CC_1D_2DOF(1);
const int CC_2D_4DOF(2);
const double CC_INIT_TIME(3.0);
// Cursor control target modes
const int CC_STAT_TARGETS(0);
const int CC_MOVING_TARGETS(1);
// Cursor control filtering modes
const int CC_BAYES_FILT(0);
const int CC_LINEAR_FILT(1);

// Biofeedback machine commands
#define COMMAND_MOTOR_ON 0x10
#define COMMAND_MOTOR_OFF 0x20
#define COMMAND_EMG_ON 0x50
#define COMMAND_EMG_OFF 0x60
#define COMMAND_SET_MOTOR_SPEED 0x90
#define COMMAND_RELEASE_MOTOR_SPEED 0xFF
#define COMMAND_BLUETOOTH_ON 0xA0
#define COMMAND_BLUETOOTH_OFF 0xB0
