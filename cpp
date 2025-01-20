[POC] 1, 1.1, 1.2, 1.2.1
Application [1] [POC]
    ::Driver Registration::
    ::Login:: 

    ::Driver Registration:: [1.1][POC] 
        - page title
        - form : name, password, email, phone, 
                 car_number, car_model, car_type 
            - fields: (caption, error message(s))
                name {required}
                password {required, strength}
                email {required, isEmail, isExist}
                phone {required, 10-digits isPhoneNumber, isExist}
                car_number {required, isExist}
                car_model {required}
                car_type {selectable}
        - on form submit: 
            - allow to edit field / group of fields !XXX
            - OR Confirm  
            - OR Exit  
        - after form submit:
            - successful message 
    ::Login:: [1.2] [POC]
        - page title
        - form : username, password (caption, error message(s))
            - fields 
                username {required}
                password {required}
            - on form submit 
                - Logging Into App 
                OR
                - Invalid Username / Password message.
            - after form submit: 
                - successful message welcoming the user 
                - DISPATCH / ROUTE to the page 
        ::Driver Page::
            ::Home Page:: [1.2.1] [POC]
                - page title
                Welcome minhaj!
                Car: TN48 Z1020, Innova, SUV, Parking:[10-Feb-2025 10:00-21:00, Spot: GR-001 / Not Parked]
                Reservation History ![last 10 - sort by date desc]
                    Date    Start Time      End Time    Amount 
                Nav Pages: 
                    [1] View/Edit Profile [2] Do Reservation / [3] Pay and Unpark 
                    [4] Change Password 
                    [99] Logout 
            ::Do Reservation:: [1.2.1.2] 
                - page title
                Welcome minhaj!
                Car: TN48 Z1020, Innova, SUV, Parking: Not Parked
                 - form : date, start_time, end_time
                    - fields 
                        date {required, isDate}
                        start_time {required, isTime}
                        end_time {required, isTime}
                    - on form submit: 
                        - allow to edit field / group of fields !XXX
                        - OR Confirm  
                        - OR Exit  
                    - after form submit:
                        - parking spot is allocated
                        - successful message 
                            - booking number is generated
            ::Pay and Unpark:: [1.2.1.3]
                - page title
                Welcome minhaj!
                Car: TN48 Z1020, Innova, SUV, Parking:10-Feb-2025 10:00-21:00, Spot: GR-001
                 - form : pay_mode 
                    - fields                        
                        actial_end_time {required, isTime} !!!{display <systetime>}
                        duration {display <calculated>}
                        amount  {display <calculated>}
                        pay_mode {selectable}
                    - on form submit: 
                        - OR Confirm  
                        - OR Exit  
                    - after form submit:
                        - successful message 
                            - payment receipt number is generated
            ::Driver Profile:: [1.2.1.1]
                - page title
                - form : name, email, phone, 
                        car_number, car_model, car_type !!if no parking history 
                    - fields: (caption, error message(s))
                        name {required}
                        email {required, isEmail, isExist}
                        phone {required, 10-digits isPhoneNumber, isExist}
                        car_number {required, isExist}
                        car_model {required}
                        car_type {selectable}
                - on form submit: 
                    - allow to edit field / group of fields !XXX
                    - OR Confirm  
                    - OR Exit  
                - after form submit:
                    - successful message 
            ::Change Password: [1.2.1.4]
                - page title
                - form : old_password, new_password
                    - fields: (caption, error message(s))
                        old_password {required}
                        new_password {required, strength}
                - on form submit: 
                    - OR Confirm  
                    - OR Exit  
                - after form submit:
                    - successful message 
                        - logout 
        ::Admin Page::
            ::Home Page:: [1.2.2]
                -Nav Pages: 
                    [1] Admins Management [2] Floor Management [3] Spot Management 
                    [4] Bookings History [5] Payments History
                    [99] Logout 
            ::Admins Management:: [1.2.2.1]
                -Nav Pages: 
                    [1] Create [2] Edit [3] Search [4] Delete
                    [5] Change Password 
                    [99] Exit 
            ::Floor Management:: [1.2.2.2]
                    [1] Create [2] Edit [3] Search [4] Delete 
                    [5] Display Spots Availability
                    [99] Exit
            ::Spot Management:: [1.2.2.3]
                    [1] Create [2] Edit [3] Search [4] Delete 
                    [99] Exit    
            ::Bookings History:: [1.2.2.4]
                    ::Today Bookings:: 
                        -----------------------------------------------------------------------------
                        |Time       |Car               |Driver       |Parking                       |
                        -----------------------------------------------------------------------------
                         10:00       TN 45 Z1020        Minhaj       GR-001 10:00-21:00
                         06:00       TN 45 Z1020        Babu         GR-001 03:00-05:00
                     
                    
                    ::Bookings By Date::
                        - page title
                        - form : date
                        - fields: (caption, error message)
                            date {required}
                        - on form submit:
                        --------------------------------------------------------------------------
                        |Time       |Car             |Driver      |Parking                       |
                        --------------------------------------------------------------------------
                         10:00       TN 45 Z1020      Minhaj       GR-001  10:00-21:00
                         07:00       TN 45 Z1020      Minhaj       GR-001  03:00-05:00
                         10:00       TN 45 Z1020      Minhaj       GR-001  10:00-21:00
                         07:00       TN 45 Z1020      Minhaj       GR-001  07:00-09:00

                    ::Exit::  
                        Go to Admin Page.

            ::Payments History:: [1.2.2.5]
                    ::Today Payments::
                        ----------------------------------------------------------------------
                        |Time       |Car                |Driver      |Parking     |Amount    |
                        ----------------------------------------------------------------------
                         10:00       TN  45 Z1020        Minhaj       GR-001       1000
                     
                    ::Payments By Date::
                        - page title
                        - form : date
                        - fields: (caption, error message)
                            date {required}
                        - on form submit:
                        ----------------------------------------------------------------------
                        |Time       |Car                |Driver      |Parking     |Amount    |
                        ----------------------------------------------------------------------
                         10:00       TN  45 Z1020        Minhaj       GR-001       1000
                         10:00       TN  45 Z1020        Minhaj       GR-001       800

                    ::Exit::
                    Return to Admin page 

    
