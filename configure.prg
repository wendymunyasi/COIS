_app.speedbar := true
_app.statusbar := true
_app.tabbar := true
set design on

compile :DT_Custom2:mycontrols2.cc
set procedure to :DT_Custom2:mycontrols2.cc
set procedure to :Formcontrols:seeker.cc

//  Setup custom controls for use the reports
set procedure to :DT_Custom2:CustomReportControls2.cc
set procedure to :ReportControls:report.cc
