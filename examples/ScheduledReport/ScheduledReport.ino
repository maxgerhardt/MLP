
/* **********************************************************************************************
*  Example program to trigger a scheduled report in MegunoLink. 
*  Visit https://www.megunolink.com/documentation/scheduled-reporting/ for more information. 
*  ********************************************************************************************** */

#include "MegunoLink.h"
#include "MegunoArduinoTimer.h"

Report ReportGenerator;
MegunoArduinoTimer ReportTimer;

TimePlot ADCValuePlot;
MegunoArduinoTimer PlotTimer;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if (PlotTimer.TimePassed_Milliseconds(500))
  {
    ADCValuePlot.SendData("A0", analogRead(0));
  }

  if (ReportTimer.TimePassed_Seconds(10))
  {
    ReportGenerator.GenerateNow();
  }
}
