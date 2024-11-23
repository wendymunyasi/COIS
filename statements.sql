--Database:dBASETutorial2
Select customer.*,
  invoice.*,
  lineitem.*
From customer
  Inner Join invoice On customer."Customer ID" = invoice."Customer ID"
  Inner Join lineitem On invoice."Invoice ID" = lineitem."Invoice ID"
Order By customer."Last Name",
  customer."Customer ID",
  invoice."Order Date"