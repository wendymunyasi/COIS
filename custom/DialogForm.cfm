** END HEADER -- do not remove this line


class DialogFormCForm of BASECFORM custom from :DT_Custom2:Base.cfm
   set procedure to :DT_Custom2:mycontrols2.cc additive
   with (this)
      height = 164.0
      left = 208.0
      top = 51.0
      width = 582.0
      text = "CustomDialogForm"
      clientEdge = true
      autoCenter = true
      mdi = false
      smallTitle = true
      escExit = false
   endwith

   with (this.MYTITLETEXT1)
      text = "DIALOG FORM"
   endwith

   this.PBSAVE = new MYPUSHBUTTON(this)
   with (this.PBSAVE)
      onClick = class::PBSAVE_ONCLICK
      height = 24.0
      left = 123.0
      top = 118.0
      width = 107.0
      text = "&Ok"
   endwith

   this.PBCANCEL = new MYPUSHBUTTON(this)
   with (this.PBCANCEL)
      onClick = class::PBCANCEL_ONCLICK
      height = 24.0
      left = 334.0
      top = 118.0
      width = 107.0
      text = "&Cancel"
   endwith


   function PBCANCEL_onClick()
      // abandon changes and close the form:
		if form.rowset # NULL
			form.rowset.abandon()
		endif
		form.close()
      return

   function PBSAVE_onClick()
      // Save and close the form:
		if form.rowset # NULL
			form.rowset.save()
		endif
		form.close()
      return

endclass

