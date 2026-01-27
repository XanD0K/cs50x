-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Figuring out the database
.schema
.table

-- Starting point (from instructions)
.schema crime_scene_reports
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street = 'Humphrey Street';
-- With that I have that teft took place at 10:15AM at Humphrey Street's bakery.
-- I also know that all interviewers mentioned the bakery

-- Investigating interviews' transcript
.schema interviews
SELECT * FROM interviews WHERE day = 28 AND month = 7 AND transcript LIKE '%bakery%';
-- Within 10 minutes from the theft, the thief got into a car in the bakery's parking lot and left. Investigate security footage from that place (bakery_security_logs table)
-- Earlier in that morning, the thief withdrew money from ATM on Leggett Street. Investigate ATM log (atm_transactions table) and maybe Bank log (bank_accounts table)
-- Called someone (less than 1 minute). They would take the earliest flight out of Fiftyville on the following day (07/29/2024).
-- Thief asked the person on the other end of the phone to purchase the flight ticket.

-- Investigating bakery's secuity footage
.schema bakery_security_logs
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND activity = 'exit' AND hour = 10 AND minute <= 25;
-- That gives me a list of suspects that used that exited the parking lot within 10 minutes from the theft

-- Investigating ATM log
.schema atm_transactions
SELECT * FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
-- It gives me informations about everyone that used that ATM machine

-- Investigating Bank log
.schema bank_accounts
SELECT * FROM bank_accounts WHERE account_number IN
 (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw');
-- It gives me everything from the bank account from everyone that accessed that ATM machine

-- Getting the name of the owners of those bank accounts
.schema people
SELECT * FROM people WHERE id IN
 (SELECT person_id FROM bank_accounts WHERE account_number IN
  (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'));

-- Now I need to investigate the license_plate, phone_number and passport_number from the table above
-- Investigating license_plate
.schema license_plate
SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND activity = 'exit' AND hour = 10 AND minute <= 25 AND license_plate IN
 (SELECT license_plate FROM people WHERE id IN
  (SELECT person_id FROM bank_accounts WHERE account_number IN
   (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')));
-- From everyone that parked in that parking lot AND used that ATM machine, our suspect's list is down to 5: 94KL13X, 4328GD8, L93JTIZ and 322W7JE

-- Narrowing down with 'people' table
SELECT * FROM people WHERE id IN
 (SELECT person_id FROM bank_accounts WHERE account_number IN
  (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'))
AND license_plate IN
 (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND activity = 'exit' AND hour = 10 AND minute <= 25 AND license_plate IN
  (SELECT license_plate FROM people WHERE id IN
   (SELECT person_id FROM bank_accounts WHERE account_number IN
    (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'))));


-- Investigating phone numbers
.schema phone_calls
SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60;
-- I know that the thief and its accomplice's phone numbers are in there
SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60 AND caller IN
 (SELECT phone_number FROM people WHERE id IN
  (SELECT person_id FROM bank_accounts WHERE account_number IN
   (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')));
-- Caller: (367) 555-5533, (286) 555-6063, (770) 555-1861, (826) 555-1652 and (338) 555-6650
-- Receiver (Accomplice): (375) 555-8161, (676) 555-6554, (725) 555-3243, (066) 555-9701 and (704) 555-2131

-- Putting everything together
SELECT * FROM people WHERE id IN
 (SELECT person_id FROM bank_accounts WHERE account_number IN
  (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'))
AND license_plate IN
 (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND activity = 'exit' AND hour = 10 AND minute <= 25 AND license_plate IN
  (SELECT license_plate FROM people WHERE id IN
   (SELECT person_id FROM bank_accounts WHERE account_number IN
    (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'))))
AND phone_number IN
 (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60 AND caller IN
  (SELECT phone_number FROM people WHERE id IN
   (SELECT person_id FROM bank_accounts WHERE account_number IN
    (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'))));
-- I have a list of 2 suspects: Diana and Bruce. Both exited that parking lot at that time, both withdrew money from that ATM machine and both called someone at that day

-- Last thing to do: check passports, airports, flights
.schema airports
.schema flights
.schema passengers

-- Checking Fiftyville airport's
SELECT * FROM airports WHERE city = 'Fiftyville';
-- Gives me accesss to it's ID

-- Informations of all flights that departured on 29th of July
SELECT * FROM flights WHERE day = 29 AND month = 7 AND origin_airport_id =
 (SELECT id FROM airports WHERE city = 'Fiftyville')
ORDER BY hour, minute;

-- Informations of first flight that departured on 29th of July
SELECT * FROM flights WHERE day = 29 AND month = 7 AND origin_airport_id =
 (SELECT id FROM airports WHERE city = 'Fiftyville')
ORDER BY hour, minute
LIMIT 1;

-- Getting passegers informations from that flight
SELECT * FROM passengers WHERE flight_id =
 (SELECT id FROM flights WHERE day = 29 AND month = 7 AND origin_airport_id =
  (SELECT id FROM airports WHERE city = 'Fiftyville') ORDER BY hour, minute LIMIT 1);

-- Checking if Bruce or Diana were in that flight
SELECT passport_number FROM passengers WHERE flight_id =
 (SELECT id FROM flights WHERE day = 29 AND month = 7 AND origin_airport_id =
  (SELECT id FROM airports WHERE city = 'Fiftyville') ORDER BY hour, minute LIMIT 1)
AND passport_number IN
 (SELECT passport_number FROM people WHERE id IN
  (SELECT person_id FROM bank_accounts WHERE account_number IN
   (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'))
AND license_plate IN
 (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND activity = 'exit' AND hour = 10 AND minute <= 25 AND license_plate IN
  (SELECT license_plate FROM people WHERE id IN
   (SELECT person_id FROM bank_accounts WHERE account_number IN
    (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'))))
AND phone_number IN
 (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60 AND caller IN
  (SELECT phone_number FROM people WHERE id IN
   (SELECT person_id FROM bank_accounts WHERE account_number IN
    (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')))));
-- Got the thief! His passport number is '5773159633'

-- Final steps: let's find out who is the owner of that passport number, and then check it's accomplice and where did he went to
-- Thief's name
SELECT name FROM people WHERE passport_number IN
 (SELECT passport_number FROM passengers WHERE flight_id =
  (SELECT id FROM flights WHERE day = 29 AND month = 7 AND origin_airport_id =
   (SELECT id FROM airports WHERE city = 'Fiftyville') ORDER BY hour, minute LIMIT 1)
AND passport_number IN
 (SELECT passport_number FROM people WHERE id IN
  (SELECT person_id FROM bank_accounts WHERE account_number IN
   (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'))
AND license_plate IN
 (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND activity = 'exit' AND hour = 10 AND minute <= 25 AND license_plate IN
  (SELECT license_plate FROM people WHERE id IN
   (SELECT person_id FROM bank_accounts WHERE account_number IN
    (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'))))
AND phone_number IN
 (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60 AND caller IN
  (SELECT phone_number FROM people WHERE id IN
   (SELECT person_id FROM bank_accounts WHERE account_number IN
    (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'))))));
-- It was Bruce!

-- Where did he escape to
SELECT city FROM airports WHERE id =
 (SELECT destination_airport_id FROM flights WHERE day = 29 AND month = 7 AND origin_airport_id =
  (SELECT id FROM airports WHERE city = 'Fiftyville')
ORDER BY hour, minute
LIMIT 1);
-- He escaped to New York City

-- Accomplice
-- Bruce's phone number
SELECT phone_number FROM people WHERE id IN
 (SELECT person_id FROM bank_accounts WHERE account_number IN
  (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'))
AND name = 'Bruce';

-- Accomplice's number
SELECT receiver FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60 AND caller =
 (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60 AND caller IN
  (SELECT phone_number FROM people WHERE id IN
   (SELECT person_id FROM bank_accounts WHERE account_number IN
    (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'))));

-- All accomplice's informations
SELECT * FROM people WHERE phone_number =
 (SELECT receiver FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60 AND caller =
  (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60 AND caller IN
   (SELECT phone_number FROM people WHERE id IN
    (SELECT person_id FROM bank_accounts WHERE account_number IN
     (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')))));

-- Accomplice's name
SELECT name FROM people WHERE phone_number =
 (SELECT receiver FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60 AND caller =
  (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60 AND caller IN
   (SELECT phone_number FROM people WHERE id IN
    (SELECT person_id FROM bank_accounts WHERE account_number IN
     (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')))));
-- Robin is the accomplice

-- Didn't use any 'JOIN' so the queries are long and complex to read
-- TODO: Complete the Fiftyville problem with better queries (using explict and implicit JOIN's)
