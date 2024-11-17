** END HEADER -- do not remove this line

class DataFormCForm of BASECFORM custom from :DT_Custom2:Base.cfm
   set procedure to :DT_Custom2:mycontrols2.cc additive
   set procedure to :FormControls:seeker.cc additive
   with (this)
      onOpen = class::FORM_ONOPEN
      height = 736.0
      left = 119.0
      top = 20.0
      width = 764.0
      text = "CustomDataForm"
      escExit = false
   endwith

   with (this.MYTITLETEXT1)
      text = "DATA FORM"
   endwith

   this.MYTABBOX1 = new MYTABBOX(this)
   with (this.MYTABBOX1)
      height = 22.0
      left = 0.0
      top = 712.0
      width = 762.0
   endwith

   this.SEEKER1 = new SEEKER(this)
   with (this.SEEKER1)
      height = 39.0
      left = 105.0
      top = 9.0
      width = 607.0
      pageno = 2
   endwith

   this.MYTEXTLABEL1 = new MYTEXTLABEL(this)
   with (this.MYTEXTLABEL1)
      height = 22.0
      left = 35.0
      top = 19.0
      width = 53.0
      text = "Find:"
      pageno = 2
   endwith

   this.MYGRID1 = new MYGRID(this)
   with (this.MYGRID1)
      pageno = 2
      height = 591.0
      left = 13.0
      top = 79.0
      width = 731.0
   endwith

   this.MYTOOLBAR1 = new MYTOOLBAR(this)
   with (this.MYTOOLBAR1)
      left = 146.0
      top = 37.0
      width = 470.0
      height = 34.0
   endwith


   function form_onOpen()
      if form.rowset # null
			// don't allow automatic editing
			form.rowset.autoEdit := false 
			// assign this method to the rowset's canNavigate:
			form.rowset.canNavigate := class::rowset_canNavigate
			// go to the first row ...
			form.rowset.first()
		endif
      return

   function rowset_canNavigate()
      /*
			Check to save any changes before allowing navigation.
			For whatever reason, this gets called twice. If the
			user chooses Yes to Save, or No to abandon, then
			the next time through the rowset.modified property is
			false so there's no problem. If the user chooses to
			cancel the navigation, they'll get prompted twice.
			For that reason, we set a flag to indicate it's been
			here once. If the flag exists, we null it, if not we 
			run the validation.

			BIG Note: If a future version of dBASE™ PLUS corrects the
			behavior so the canNavigate routine does NOT fire
			twice, this code will not work correctly.
		  
			Applies to all dBASE builds through dBASE™ PLUS.

			Code by Gary White
		*/
		local bYes, nAnswer
		if type("_app.cancelNav") == "L" and _app.cancelNav
			_app.cancelNav := null
			bYes = false
		else
			bYes = true
			if this.modified
				nAnswer = msgbox("Save changes before leaving record?",;
							  "Data has changed",32+3)
				do case
					case nAnswer == 6 // Yes
						this.save()
					case nAnswer == 7 // No
						this.abandon()
					otherwise         // Cancel
						bYes := false
						_app.cancelNav = true
				endcase
			endif
		endif
		return bYes
      

endclass

