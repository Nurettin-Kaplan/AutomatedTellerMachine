### ATM System

---

#### Overview
This project is an ATM system implemented in C. Users can check their account balance, deposit money, and withdraw money through this ATM system. It also includes an authentication mechanism for user login.

---

#### Features

- **Login**: Login with username and password.
- **Check Balance**: View account balance.
- **Deposit**: Deposit money into the account.
- **Withdraw**: Withdraw money from the account.
- **File Update**: Save user balance to a file.

---

#### Installation

1. **Download the Code:**

   Clone the repository from GitHub or download the source code from another source.

   ```bash
   git clone https://github.com/Nurettin-Kaplan/AutomatedTellerMachine.git
   ```

2. **Compile**

   To compile the code, run the following command in your terminal or command prompt:

   ```bash
   gcc -o ATM ATM.c
   ```

   Here, `ATM.c` should be the name of your source file, and `ATM` is the name of the executable file that will be created.

3. **Run**

   After a successful compilation, run the program with:

   ```bash
   ./ATM
   ```

---

#### Usage

1. **Login:**

   - When the program starts, you will be prompted to enter your username and password.
   - The program will exit after three failed login attempts.

2. **Main Menu:**

   The main menu provides the following options:
   - **1:** Check balance
   - **2:** Deposit money
   - **3:** Withdraw money
   - **4:** Exit the program

   You can select the desired operation by entering the corresponding number.

---

#### Files

- **ATM.c:** Source code for the ATM system.
- **users.txt:** File containing user information (username, password, and balance).
- **newUsers.txt:** Temporarily used file for updating user information.

---

#### License

This project is licensed under the [MIT License](https://github.com/Nurettin-Kaplan/AutomatedTellerMachine/blob/master/LICENSE.txt).

---

#### Author

[Nurettin Kaplan](https://github.com/Nurettin-Kaplan) - Project owner and developer.

---

#### Contact

For any questions or issues, you can reach out via [email address](nurettinkaplaan@gmail.com).

---

#### Notes

Ensure that `users.txt` contains the necessary user information for the system to function correctly.
