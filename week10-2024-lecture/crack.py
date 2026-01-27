from string import digits  # Library to get decimal digitis so you don't haveto manually type 0 through 9
from string import ascii_letters  # Get all letters in alphabet
from string import punctuation  # Get 32 ponctuation symbols
from itertools import product  # Function that allow combine all numbers multiple times

for passcode in product(digits, repeat=4):  # 'repeat 4' because password will have 4 digits
    print(passcode)

for passcode in product(ascii_letters, repeat=4):
    print(passcode)

for passcode in product(digits + ascii_letters + punctuation, repeat=8):
    print(passcode)

# Devices should prevent malicous users to allow all those tries!
# For example, set a limited number of tries, or a timer for a new try

# Password Managers automatically manages passwords and usernames, create strong passwords, etc. (like apple keychan)

# Two-factor authenticaton requires not just a password known by the user (first factor), and something that user has (second factor)
# That second factor can be a phone, an application, a keychain, biometrics, etc
# They send a one-time passcode, which is further secure because it's has a one time usage only

# Use hash functions to store teh hashed passwords. Never store the raw password (the password itself)
# Rainbow table
# It's a dictionary with pre-stored all 4-digit characters/8-digit characters/etc already hashed
# So malicious users could possible "reverse engineer" the hash
# But it doesn't "defeat" passwords because it not only would take too long to break, but a 8-digit password allow more than 4 quadrillion possiblities
# Different users, with the same password, might have the same hashed password
# Salting -> the hash functions takes 2 inputs: the password but other value (salt)
# That salt can be short or long, but it will change the output (the whole hashed password), which will cover up the fact that 2 different users have the same password

# Cryptography
# Secret-key cryptography
# Symmetric cryptography
# Asymmetric cryptography
# Public-key cryptography

# Passkeys
# It doesn't require user to choose an username and password
# Your device generates a public and private key pair, and it will send to the website the public key

# end-to-end encryption

