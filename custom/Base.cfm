
** END HEADER -- do not remove this line




class BaseCForm of FORM custom
   set procedure to :DT_Custom2:mycontrols2.cc additive
   with (this)
      onGotFocus = class::FORM_ONGOTFOCUS
      onLostFocus = class::FORM_ONLOSTFOCUS
      canClose = class::FORM_CANCLOSE
      onClose = class::FORM_ONCLOSE
      doubleBuffered = true
      metric = 6	// Pixels
      height = 790.0
      left = 159.0
      top = 20.0
      width = 804.0
      text = "Base Form"
   endwith

   this.MYTITLETEXT1 = new MYTITLETEXT(this)
   with (this.MYTITLETEXT1)
      height = 28.0
      left = 0.0
      top = 0.0
      width = 802.0
      anchor = 2	// Top
      text = "BASE FORM"
   endwith


   function Repaint
      parameter oForm
		if type( "oForm" ) == "U" or empty( oForm )
			oForm = form
		endif
		if type( "UpdateWindow" ) # "FP"
			extern CLOGICAL UpdateWindow( CHANDLE ) USER32
		endif
		return UpdateWindow( oForm.hWnd )


   function form_canClose()
      // avoid closing the form in the wrong state
		// If we have a rowset on the form, we need
		// to check the state -- 2 = Edit, 3 = Append
		if form.rowset # NULL and;
			(form.rowset.state == 2 or form.rowset.state == 3)
			// if the row's been modified ...
			if form.rowset.modified
				nAnswer = msgbox("Save changes before leaving record?",;
									  "Data has changed",32+3)
				// check the answer returned by clicking a button
				// in the message box
				do case
					case nAnswer == 6
						form.rowset.save()
					case nAnswer == 7
						form.rowset.abandon()
					otherwise
						return false
				endcase
			endif
		endif
      return true

   function form_onClose()
      this.release()
      return

   function form_onGotFocus()
      // set application reference to this form:
		if type( "_app.framewin" ) # "U"
			_app.framewin.currentForm = this
		endif
		form.repaint() 
      return

   function form_onLostFocus()
      // null out application's reference to this form:
		if type( "_app.framewin.currentForm" ) # "U"
			_app.framewin.currentForm := null
		endif
      return

endclass

