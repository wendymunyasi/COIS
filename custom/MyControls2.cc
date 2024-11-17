class MYENTRYFIELD(parentObj) of ENTRYFIELD(parentObj) custom
   with (this)
      onGotFocus = {||"this.keyboard( "}
      height = 22.0
      left = 55.0
      top = 34.0
      width = 101.0
      metric = 6	// Pixels
      colorHighLight = "WindowText/0x80ffff"
      value = "MyEntryfield"
      selectAll = false
   endwith

endclass

class MYTEXT(parentObj) of TEXT(parentObj) custom
   with (this)
      height = 22.0
      left = 100.0
      top = 140.0
      width = 84.0
      metric = 6	// Pixels
      text = "Text1"
      borderStyle = 10	// Etched Out
   endwith

endclass

class MYTEXTLABEL(parentObj) of TEXTLABEL(parentObj) custom
   with (this)
      height = 22.0
      left = 100.0
      top = 246.0
      width = 84.0
      metric = 6	// Pixels
      transparent = true
      text = "Textlabel1"
      fontBold = true
      alignHorizontal = 2	// Right
   endwith

endclass

class MYPUSHBUTTON(parentObj) of PUSHBUTTON(parentObj) custom
   with (this)
      height = 24.0
      left = 98.0
      top = 328.0
      width = 107.0
      text = "Button"
      metric = 6	// Pixels
   endwith

endclass

class MYSPINBOX(parentObj) of SPINBOX(parentObj) custom
   with (this)
      onGotFocus = {||"this.keyboard("}
      height = 22.0
      left = 117.0
      top = 393.0
      width = 56.0
      metric = 6	// Pixels
      colorHighLight = "WindowText/0x80ffff"
      rangeMax = 100
      rangeMin = 1
      value = 1
      selectAll = false
   endwith

endclass

class MYCOMBOBOX(parentObj) of COMBOBOX(parentObj) custom
   with (this)
      onGotFocus = class::MYCOMBOBOX_ONGOTFOCUS
      onChange = class::MYCOMBOBOX_ONCHANGE
      height = 22.0
      left = 96.0
      top = 473.0
      width = 84.0
      metric = 6	// Pixels
      colorHighLight = "WindowText/0x80ffff"
      style = 2	// DropDownList
      dropDownHeight = 132.0
      autoDrop = true
   endwith

   function MYCOMBOBOX_onGotFocus()
      this.savedValue = this.value
      return
   function MYCOMBOBOX_onChange()
      // this = combobox
		// datalink = field
		// parent = field array
		// parent = rowset
		if this.datalink.parent.parent.state == 1
			this.value = this.savedValue
			this.datalink.parent.parent.modified = false
			this.datalink.parent.parent.abandon()
		endif
      return
endclass

class MYRADIOBUTTON(parentObj) of RADIOBUTTON(parentObj) custom
   with (this)
      transparent = true
      height = 24.0
      left = 84.0
      top = 541.0
      width = 110.0
      text = "MyRadiobutton"
      metric = 6	// Pixels
   endwith

endclass

class MYCONTAINER(parentObj) of CONTAINER(parentObj) custom
   with (this)
      transparent = true
      left = 369.0
      top = 41.0
      width = 369.0
      height = 173.0
      metric = 6	// Pixels
      borderStyle = 4	// Single
   endwith

endclass

class MYGRID(parentObj) of GRID(parentObj) custom
   with (this)
      bgColor = "white"
      headingHeight = 22.0
      cellHeight = 22.0
      rowSelect = true
      colorRowSelect = "WindowText/0x80ffff"
      allowEditing = false
      allowAddRows = false
      height = 169.0
      left = 375.0
      top = 257.0
      width = 181.0
      metric = 6	// Pixels
   endwith

endclass

class MYTABBOX(parentObj) of TABBOX(parentObj) custom
   with (this)
      onSelChange = class::MYTABBOX_ONSELCHANGE
      onOpen = class::MYTABBOX_ONOPEN
      id = 110
      height = 22.0
      left = 0.0
      top = 772.0
      width = 900.0
      metric = 6	// Pixels
      colorHighLight = "WindowText/0x80ffff"
      dataSource = 'ARRAY {"Individual Record","Find Record"}'
   endwith

   function MYTABBOX_onSelChange()
      form.pageNo := this.curSel
      return
   function MYTABBOX_onOpen()
      this.curSel := 1
      form.pageNo := 1
      return
endclass

class MYIMAGE(parentObj) of IMAGE(parentObj) custom
   with (this)
      height = 163.0
      left = 580.0
      top = 258.0
      width = 191.0
      metric = 6	// Pixels
      alignment = 3	// Keep Aspect Stretch
   endwith

endclass

class MYEDITOR(parentObj) of EDITOR(parentObj) custom
   with (this)
      key = class::MYEDITOR_KEY
      height = 149.0
      left = 588.0
      top = 448.0
      width = 177.0
      metric = 6	// Pixels
      value = ""
      colorHighLight = "WindowText/0x80ffff"
      evalTags = false
      popupEnable = false
   endwith

   function MYEDITOR_key(nChar, nPosition,bShift,bControl)
      /*
			This code by Gary White is provided to
			get around a problem with rowsets that
			have the autoEdit property set to false,
			and editors. The editor seems to be immune
			to this property once you make a change
			in it -- if you then save or abandon, you
			can actually edit the contents of the editor
			object ...
		*/
		// this = editor
		// dataLink = field
		// parent = fieldArray
		// parent = rowset
		if type( "this.datalink.parent.parent" ) # "U"
			r = this.datalink.parent.parent
			if r.autoEdit == false and ;
				( r.state # 2 and r.state # 3 )
				return 0
			endif
		endif
      return
endclass

class MYDISABLEDENTRYFIELD(parentObj) of MYENTRYFIELD(parentObj) custom
   with (this)
      when = {;return false}
      height = 22.0
      left = 85.0
      top = 592.0
      width = 130.0
      colorNormal = "White/Maroon"
      value = "MyDisabledEntryfield"
      mousePointer = 12	// No
   endwith

endclass

class MYTITLETEXT(parentObj) of MYTEXT(parentObj) custom
   with (this)
      height = 28.0
      left = 489.0
      top = 634.0
      width = 160.0
      colorNormal = "BLUE/BtnFace"
      alignHorizontal = 1	// Center
      fontSize = 14.0
      fontBold = true
      text = "MYTITLETEXT"
      borderStyle = 1	// Raised
   endwith

endclass

class MYTOOLBAR(parentObj) of CONTAINER(parentObj) custom
   with (this)
      left = 115.0
      top = 703.0
      width = 470.0
      height = 34.0
      metric = 6	// Pixels
      borderStyle = 4	// Single
   endwith

   this.PBNEW = new MYPUSHBUTTON(this)
   with (this.PBNEW)
      onClick = class::PBNEW_ONCLICK
      height = 24.0
      left = 15.0
      top = 4.0
      width = 70.0
      text = "&New"
      upBitmap = "filename :Glyfx:\Aero\CE\Dbase Aero\PNG\16x16\favourites_16.png"
      fontSize = 8.0
      speedTip = "Add a new record"
      pageno = 0
   endwith

   this.PBEDIT = new MYPUSHBUTTON(this)
   with (this.PBEDIT)
      onClick = class::PBEDIT_ONCLICK
      height = 24.0
      left = 89.0
      top = 4.0
      width = 70.0
      text = "&Edit"
      upBitmap = "filename :Glyfx:\Aero\CE\Dbase Aero\PNG\16x16\document_open_16.png"
      fontSize = 8.0
      speedTip = "Edit current record"
      pageno = 0
   endwith

   this.PBSAVE = new MYPUSHBUTTON(this)
   with (this.PBSAVE)
      onClick = class::PBSAVE_ONCLICK
      height = 24.0
      left = 165.0
      top = 4.0
      width = 70.0
      text = "&Save"
      upBitmap = "filename :Glyfx:\Aero\CE\Dbase Aero\PNG\16x16\save_16.png"
      fontSize = 8.0
      speedTip = "Save current record"
      pageno = 0
   endwith

   this.PBCANCEL = new MYPUSHBUTTON(this)
   with (this.PBCANCEL)
      onClick = class::PBCANCEL_ONCLICK
      height = 24.0
      left = 240.0
      top = 4.0
      width = 70.0
      text = "&Cancel"
      upBitmap = "filename :Glyfx:\Aero\CE\Dbase Aero\PNG\16x16\stop_16.png"
      fontSize = 8.0
      speedTip = "Cancel changes"
      pageno = 0
   endwith

   this.PBDELETE = new MYPUSHBUTTON(this)
   with (this.PBDELETE)
      onClick = class::PBDELETE_ONCLICK
      height = 24.0
      left = 317.0
      top = 4.0
      width = 70.0
      text = "&Delete"
      upBitmap = "filename :Glyfx:\Aero\CE\Dbase Aero\PNG\16x16\delete_16.png"
      fontSize = 8.0
      speedTip = "Delete current record"
      pageno = 0
   endwith

   this.PBPREV = new MYPUSHBUTTON(this)
   with (this.PBPREV)
      onClick = class::PBPREV_ONCLICK
      height = 24.0
      left = 396.0
      top = 4.0
      width = 24.0
      text = ""
      upBitmap = "filename :Glyfx:\Aero\CE\Dbase Aero\PNG\16x16\arrow_left_16.png"
      speedTip = "Previous record"
      pageno = 0
   endwith

   this.PBNEXT = new MYPUSHBUTTON(this)
   with (this.PBNEXT)
      onClick = class::PBNEXT_ONCLICK
      height = 24.0
      left = 427.0
      top = 4.0
      width = 24.0
      text = ""
      upBitmap = "filename :Glyfx:\Aero\CE\Dbase Aero\PNG\16x16\arrow_right_16.png"
      speedTip = "Next record"
      pageno = 0
   endwith

   function PBSAVE_onClick()
      form.rowset.save()
      return
   function PBNEXT_onClick()
      if ( not form.rowset.next() )
			form.rowset.next( -1 )
			msgbox( "At end of rowset", "Can't Navigate", 64 )
		endif
      return
   function PBDELETE_onClick()
      if msgbox( "Delete this row?", "Delete Row?", 36 ) == 6
						form.rowset.delete()
		endif
      return
   function PBEDIT_onClick()
      form.rowset.beginEdit()
      return
   function PBPREV_onClick()
      if ( not form.rowset.next(-1) )
			form.rowset.next()
			msgbox( "At beginning of rowset", "Can't Navigate", 64 )
		endif
      return
   function PBCANCEL_onClick()
      if form.rowset.modified
			if msgbox( "Abandon changes to this row?", "Abandon changes?", 36 ) == 6
				form.rowset.abandon()
			endif
		else
			form.rowset.abandon()
		endif
      return
   function PBNEW_onClick()
      form.rowset.beginAppend()
      return
endclass
