struct userconfig_t {
  bool DebugMode = false;       //Enable or disable the Debugmode -> serial output
  int max_Distance = 200;      // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
  int measuringInterval = 2000;  //
} UserConfig;

void print_config()
{
  
}
