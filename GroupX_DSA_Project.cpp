#include <iostream>	
#include <string>
#include <fstream>
#include <iomanip> 
#include <conio.h>
#include <sstream>


using namespace std;


// ANSI escape codes for text color
const string ANSI_RED = "\033[31m";
const string ANSI_BLUE = "\033[34m";
//Code to change bg color
const string ANSI_RESET = "\033[44m";
const string ANSI_WHITE_BG = "\033[47m";


static void design()
{
	cout << "\t\t\t  ***********************************" << endl;
	cout << "\t\t\t  ***********************************" << endl;
	cout << "\t\t\t  *                                 *" << endl;
	cout << "\t\t\t  *                                 *" << endl;
	cout << "\t\t\t  *      Welcome to ABC ATM         *" << endl;
	cout << "\t\t\t  *          Simulator              *" << endl;
	cout << "\t\t\t  *                                 *" << endl;
	cout << "\t\t\t  *                                 *" << endl;
	cout << "\t\t\t  ***********************************" << endl;
	cout << "\t\t\t  ***********************************" << endl;

}

int GetNumberInput(int maxLength)
{
	char inputBuffer[11];
	if (maxLength > 10) maxLength = 10;

	char ch;
	int i = 0;

	while (i < maxLength)
	{
		ch = _getch();

		if (ch >= '0' && ch <= '9')
		{
			if (i < 10) // Prevent buffer overflow
			{
				cout << ch;
				inputBuffer[i] = ch;
				i++;
			}
		}
		else if (ch == '\r')
		{
			break;
		}
		else if (ch == '\b' && i > 0)
		{
			cout << "\b \b";
			i--;
		}
	}

	cout << "\n";

	if (i < sizeof(inputBuffer) - 1) {
		inputBuffer[i] = '\0';
	}
	else {
		inputBuffer[sizeof(inputBuffer) - 1] = '\0';
	}

	return atoi(inputBuffer);
}

class AdminData {
public:
	string StoredAccountNO;
	string StoredPIN;


	AdminData* next;

	// Constructor
	AdminData() : next(nullptr) {}
};


struct PERSON {
	int balance[10] = { 0 };
	string StoredAccountNO[10];
	string StoredPIN[10];
	string StoredFrstName[10];
	string StoredLstName[10];
	string StoredCNIC[10];
	string StoredNO[10];
	string StoredCity[10];
	string StoredMail[10];
	int gender[10] = { 0 };
	int StoredAmount[10] = { 0 };
	int transact = 0;
	string AccountNumber, pin;
	int depositAmount = 0;

} Person_Data;



class BANK
{
protected:
	string bankName;
	string bankLocation;

public:
	BANK() : bankName("ABC Bank"), bankLocation("Kharian Branch")
	{

	}

	BANK(string name, string location) : bankName(name), bankLocation(location)
	{
	}

	void displayBankInfo()
	{

		cout << "Bank Name: " << bankName << endl;
		cout << "Bank Location: " << bankLocation << endl;


	}
	void displayLocalDateTime()
	{
		time_t currentUnixTime;
		time(&currentUnixTime);

		struct tm localTimeStruct;
		localtime_s(&localTimeStruct, &currentUnixTime);

		char timeString[26];
		asctime_s(timeString, sizeof(timeString), &localTimeStruct);
		cout << timeString;
	}
};


class AccountHolder : virtual public BANK
{
public:
	void QuickCash()
	{
		int fcash;
		string FindID = Person_Data.AccountNumber;
		system("cls");
		bool accountFound = false;

		fstream FastCashReadingAmount;
		FastCashReadingAmount.open("UserInfo.txt", ios::in);

		if (!FastCashReadingAmount) {
			cout << "\n\n\n\t\t\t  Error opening file." << endl;
			exit(1);
		}
		else
		{
			for (int i = 0; i < 10; i++)
			{
				FastCashReadingAmount >> Person_Data.StoredAccountNO[i] >> Person_Data.balance[i] >> Person_Data.StoredFrstName[i] >> Person_Data.StoredLstName[i] >> Person_Data.StoredCNIC[i] >> Person_Data.StoredNO[i] >> Person_Data.StoredPIN[i] >> Person_Data.StoredCity[i] >> Person_Data.StoredMail[i] >> Person_Data.gender[i];

				if (FindID == Person_Data.StoredAccountNO[i]) {
					accountFound = true;

					cout << "*_ * _ * _ * _ * _ * _ * _ * _ * _ * _ Account Holder Information & Detail _ * _ * _ * _ * _ * _ * _ * _ * _ * _*" << endl;
					cout << "\n\n\t\t\t  Account Number: " << Person_Data.StoredAccountNO[i] << endl;
					cout << "\n\n\t\t\t  Current Balance: " << Person_Data.balance[i] << endl;

					if (Person_Data.balance[i] >= 500)
					{
					EnterAmountAgain:
						cout << "\n\n\t\t\t  Please select the Withdrawal amount:\n";
						cout << "\n\n\t\t\t  1. Rs. 500\n\n\n\t\t\t  2. Rs. 1000\n\n\n\t\t\t  3. Rs. 1500\n\n\n\t\t\t  4. Rs. 2000\n\n\n\t\t\t  5. Rs. 2500\n\n\n\t\t\t  6. Rs. 3000\n";
						cout << "\n\n\t\t\t  Your choice: ";
						fcash = GetNumberInput(1);

						switch (fcash)
						{
						case 1:
							if (Person_Data.balance[i] >= 500)
							{
								Person_Data.balance[i] -= 500;
								cout << "\n\n\n\t\t\t  Processing withdrawal of Rs. 500..." << endl;
							}
							break;
						case 2:
							if (Person_Data.balance[i] >= 1000)
							{
								Person_Data.balance[i] -= 1000;
								Person_Data.transact += 1000;

								cout << "\n\n\n\t\t\t  Processing withdrawal of Rs. 1000..." << endl;
							}
							else {
								cout << "\n\n\n\t\t\t  Insufficient balance[i].\n\n\n\t\t\t  Try Another Amount\n" << endl;
								goto EnterAmountAgain;
							}
							break;
						case 3:
							if (Person_Data.balance[i] >= 1500)
							{
								Person_Data.balance[i] -= 1500;
								Person_Data.transact += 1500;

								cout << "\n\n\n\t\t\t  Processing withdrawal of Rs. 1500..." << endl;
							}
							else {
								cout << "\n\n\n\t\t\t  Insufficient balance[i].\n\n\n\t\t\t  Try Another Amount\n" << endl;
								goto EnterAmountAgain;
							}
							break;
						case 4:
							if (Person_Data.balance[i] >= 2000)
							{
								Person_Data.balance[i] -= 2000;
								Person_Data.transact += 2000;

								cout << "\n\n\n\t\t\t  Processing withdrawal of Rs. 2000..." << endl;
							}
							else {
								cout << "\n\n\n\t\t\t  Insufficient balance[i].\n\n\n\t\t\t  Try Another Amount\n" << endl;
								goto EnterAmountAgain;
							}
							break;
						case 5:
							if (Person_Data.balance[i] >= 2500)
							{
								Person_Data.balance[i] -= 2500;
								Person_Data.transact += 2500;

								cout << "\n\n\n\t\t\t  Processing withdrawal of Rs. 2500..." << endl;
							}
							else {
								cout << "\n\n\n\t\t\t  Insufficient balance[i].\n\n\n\t\t\t  Try Another Amount\n" << endl;
								goto EnterAmountAgain;
							}
							break;
						case 6:
							if (Person_Data.balance[i] >= 3000)
							{
								Person_Data.balance[i] -= 3000;
								Person_Data.transact += 3000;

								cout << "\n\n\n\t\t\t  Processing withdrawal of Rs. 3000..." << endl;
							}
							else {
								cout << "\n\n\n\t\t\t  Insufficient balance[i].\n\n\n\t\t\t  Try Another Amount\n" << endl;
								goto EnterAmountAgain;
							}
							break;
						default:
							cout << "\n\n\n\t\t\t  Invalid Choice. Please try again." << endl;
							goto EnterAmountAgain;
							break;
						}
					}
					else
					{
						cout << "\n\n\n\t\t\t  Your balance does not meet the minimum requirement for Quick Cash." << endl;
					}
				}
			}
			FastCashReadingAmount.close();

			if (!accountFound) {
				cout << "\n\n\n\t\t\t  Invalid ID" << endl;
			}
		}

		fstream SaveDataFastCash;
		SaveDataFastCash.open("UserInfo.txt", ios::out);
		for (int i = 0; i < 10; i++)
		{
			SaveDataFastCash << Person_Data.StoredAccountNO[i] << " "
				<< Person_Data.balance[i] << " "
				<< Person_Data.StoredFrstName[i] << " "
				<< Person_Data.StoredLstName[i] << " "
				<< Person_Data.StoredCNIC[i] << " "
				<< Person_Data.StoredNO[i] << " "
				<< Person_Data.StoredPIN[i] << " "
				<< Person_Data.StoredCity[i] << " "
				<< Person_Data.StoredMail[i] << " "
				<< Person_Data.gender[i] << "\n";
		}
		SaveDataFastCash.close();
	}

	void WithDrawalCash()
	{
		system("cls");
		string FindID = Person_Data.AccountNumber;
		fstream WithdrawalReadingAmount;
		WithdrawalReadingAmount.open("UserInfo.txt", ios::in);

		if (!WithdrawalReadingAmount) {
			cout << "\n\n\n\t\t\t  Error opening file." << endl;
			return;
		}

		bool accountFound = false;

		for (size_t i = 0; i < 10; i++)
		{
			WithdrawalReadingAmount >> Person_Data.StoredAccountNO[i]
				>> Person_Data.balance[i]
				>> Person_Data.StoredFrstName[i]
				>> Person_Data.StoredLstName[i]
				>> Person_Data.StoredCNIC[i]
				>> Person_Data.StoredNO[i]
				>> Person_Data.StoredPIN[i]
				>> Person_Data.StoredCity[i]
				>> Person_Data.StoredMail[i]
				>> Person_Data.gender[i];

			if (FindID == Person_Data.StoredAccountNO[i]) {
				accountFound = true;

				cout << "*_ * _ * _ * _ * _ * _ * _ * _ * _ * _ WITHDRAWAL OPERATION PROCESSING _ * _ * _ * _ * _ * _ * _ * _ * _ * _*" << endl;
				cout << "\n\n\t\t\t  Account Number: " << Person_Data.StoredAccountNO[i] << endl;
				cout << "\n\n\t\t\t  Current Balance: " << Person_Data.balance[i] << endl;

				int wd_choice;
				int withdrawal;
			EnterAmountAgain:
				cout << "\n\n\t\t\t  Please select the Withdrawal amount:" << endl;
				cout << "\t\t\t  1. Rs. 10" << endl;
				cout << "\t\t\t  2. Rs. 500" << endl;
				cout << "\t\t\t  3. Rs. 1000" << endl;
				cout << "\t\t\t  4. Other Amount" << endl;
				cout << "\n\t\t\t  Your choice: ";
				wd_choice = GetNumberInput(1);

				switch (wd_choice) {
				case 1:
					if (Person_Data.balance[i] >= 10.0) {
						withdrawal = 10.0;
						cout << "\n\n\n\t\t\t  Processing withdrawal of Rs. 10..." << endl;
					}
					else {
						cout << "\n\n\n\t\t\t  Insufficient balance[i].\n\n\n\t\t\t  Try Another Amount\n" << endl;
						goto EnterAmountAgain;
					}
					break;
				case 2:
					if (Person_Data.balance[i] >= 500.0) {
						withdrawal = 500.0;
						cout << "\n\n\n\t\t\t  Processing withdrawal of Rs. 500..." << endl;
					}
					else {
						cout << "\n\n\n\t\t\t  Insufficient balance[i].\n\n\n\t\t\t  Try Another Amount\n" << endl;
						goto EnterAmountAgain;
					}
					break;
				case 3:
					if (Person_Data.balance[i] >= 1000) {
						withdrawal = 1000.0;
						cout << "\n\n\n\t\t\t  Processing withdrawal of Rs. 1000..." << endl;
					}
					else {
						cout << "\n\n\n\t\t\t  Insufficient balance[i].\n\n\n\t\t\t  Try Another Amount\n" << endl;
						goto EnterAmountAgain;
					}
					break;
				case 4:
					cout << "\n\t\t\t  Please Enter the Amount for withdrawal: Rs. ";
					cin >> withdrawal;
					if (Person_Data.balance[i] >= withdrawal) {
						cout << "\n\n\n\t\t\t  Processing withdrawal of Rs. " << withdrawal << "..." << endl;
					}
					else {
						cout << "\n\n\n\t\t\t  Insufficient balance[i].\n\n\n\t\t\t  Try Another Amount\n" << endl;
						goto EnterAmountAgain;
					}
					break;
				default:
					cout << "\n\t\t\t  Invalid Choice. Please try again." << endl;
					goto EnterAmountAgain;
				}

				if (withdrawal <= 0) {
					cout << "\n\t\t\t  Invalid Withdrawal Amount. Please try again." << endl;
					goto EnterAmountAgain;

				}
				else
				{
					Person_Data.transact += withdrawal;
					Person_Data.balance[i] = Person_Data.balance[i] - withdrawal;
					cout << fixed << setprecision(2);
					cout << "\n\t\t\t  Remaining Balance : " << Person_Data.balance[i];
					cout << "\n\t\t\t  Please take your Amount and remove your Card." << endl;
				}


				WithdrawalReadingAmount.close();

				fstream SaveDataWithdrawal;
				SaveDataWithdrawal.open("UserInfo.txt", ios::out);
				for (size_t j = 0; j < 10; j++)
				{
					SaveDataWithdrawal << Person_Data.StoredAccountNO[j] << " "
						<< Person_Data.balance[j] << " "
						<< Person_Data.StoredFrstName[j] << " "
						<< Person_Data.StoredLstName[j] << " "
						<< Person_Data.StoredCNIC[j] << " "
						<< Person_Data.StoredNO[j] << " "
						<< Person_Data.StoredPIN[j] << " "
						<< Person_Data.StoredCity[j] << " "
						<< Person_Data.StoredMail[j] << " "
						<< Person_Data.gender[j] << endl;
				}
				SaveDataWithdrawal.close();

				break;
			}
		}

		if (!accountFound) {
			cout << "\n\n\n\t\t\t  Invalid ID" << endl;
		}
	}

	void Deposit()
	{
		bool accountFound = false;
		string FindID = Person_Data.AccountNumber;
		fstream InfoEditor;
		InfoEditor.open("UserInfo.txt", ios::in);

		if (!InfoEditor)
		{
			cout << "\n\n\n\t\t\t  Error opening file." << endl;
			return;
		}
		else
		{
			for (size_t i = 0; i < 10; i++)
			{
				InfoEditor >> Person_Data.StoredAccountNO[i]
					>> Person_Data.balance[i]
					>> Person_Data.StoredFrstName[i]
					>> Person_Data.StoredLstName[i]
					>> Person_Data.StoredCNIC[i]
					>> Person_Data.StoredNO[i]
					>> Person_Data.StoredPIN[i]
					>> Person_Data.StoredCity[i]
					>> Person_Data.StoredMail[i]
					>> Person_Data.gender[i];

				if (FindID == Person_Data.StoredAccountNO[i]) {
					accountFound = true;

				PutAgain:
					cout << "\n\n\t\t\t  Please put the amount in the Deposit box: Rs. ";
					cin >> Person_Data.depositAmount;

					if (Person_Data.depositAmount <= 0) {
						cout << "\n\t\t\t  Invalid Deposit Amount. Please try again." << endl;
						goto PutAgain;
					}
					cout << "\n\t\t\t  Processing deposit of Rs. " << Person_Data.depositAmount << "..." << endl;

					Person_Data.balance[i] = Person_Data.balance[i] + Person_Data.depositAmount;

					cout << "\n\t\t\t  Your New Balance is: " << Person_Data.balance[i] << " Rs" << endl;
				}
			}

			InfoEditor.close();

			if (!accountFound) {
				cout << "\n\n\n\t\t\t  No Record Found..." << endl;
				cout << "\n\n\n\t\t\t  Try Again" << endl;
				return;
			}

			fstream SavingInfo;
			SavingInfo.open("UserInfo.txt", ios::out);

			if (SavingInfo.is_open()) {
				for (int i = 0; i < 10; i++)
				{
					SavingInfo << Person_Data.StoredAccountNO[i] << " "
						<< Person_Data.balance[i] << " "
						<< Person_Data.StoredFrstName[i] << " "
						<< Person_Data.StoredLstName[i] << " "
						<< Person_Data.StoredCNIC[i] << " "
						<< Person_Data.StoredNO[i] << " "
						<< Person_Data.StoredPIN[i] << " "
						<< Person_Data.StoredCity[i] << " "
						<< Person_Data.StoredMail[i] << " "
						<< Person_Data.gender[i] << "\n";
				}
				SavingInfo.close();
			}
			else
			{
				cout << "\n\n\n\t\t\t  Error in Writing Info..." << endl;
				return;
			}
		}
	}
	void TransferAmount()
	{
		string FindID = Person_Data.AccountNumber;

		system("cls");

		fstream TranferingBalance;
		TranferingBalance.open("UserInfo.txt", ios::in);

		if (!TranferingBalance) {
			cout << "\n\n\n\t\t\t  Error opening file." << endl;
			return;
		}

		bool accountFound = false;

		for (int i = 0; i < 10; i++)
		{
			TranferingBalance >> Person_Data.StoredAccountNO[i]
				>> Person_Data.balance[i]
				>> Person_Data.StoredFrstName[i]
				>> Person_Data.StoredLstName[i]
				>> Person_Data.StoredCNIC[i]
				>> Person_Data.StoredNO[i]
				>> Person_Data.StoredPIN[i]
				>> Person_Data.StoredCity[i]
				>> Person_Data.StoredMail[i]
				>> Person_Data.gender[i];

			if (FindID == Person_Data.StoredAccountNO[i]) {
				accountFound = true;

				cout << "*_ * _ * _ * _ * _ * _ * _ * _ * _ * _ TRANSFER AMOUNT OPERATION PROCESSING _ * _ * _ * _ * _ * _ * _ * _ * _ * _*" << endl;
				cout << "\n\n\t\t\t  Account Number: " << Person_Data.StoredAccountNO[i] << endl;
				cout << "\n\t\t\t  Current Balance: " << Person_Data.balance[i] << endl;

				int TransferAmount;
				cout << "\n\t\t\t  Please Enter Account ID to Transfer Funds:  \n\t\t\t  ";
				string Transferer_ID;
				cin >> Transferer_ID;
				cout << "\n\t\t\t  Enter Amount To Transfer : \n\t\t\t  ";
				cin >> TransferAmount;

				if (TransferAmount > Person_Data.balance[i]) {
					cout << "\n\n\t\t\t  Insufficient ATM Balance!\n";
				}
				else {
					Person_Data.balance[i] -= TransferAmount;
					cout << "\n\n\t\t\t  Successful Transfer of " << TransferAmount << " to " << Transferer_ID << "!\n";
				}
			}
		}

		TranferingBalance.close();

		if (!accountFound) {
			cout << "\n\n\n\t\t\t  Error in Reading Amount..." << endl;
			cout << "\n\n\n\t\t\t  Invalid ID" << endl;
			return;
		}

		fstream SaveDataForTransferFunds;
		SaveDataForTransferFunds.open("UserInfo.txt", ios::out);
		for (int i = 0; i < 10; i++)
		{
			SaveDataForTransferFunds << Person_Data.StoredAccountNO[i] << " "
				<< Person_Data.balance[i] << " "
				<< Person_Data.StoredFrstName[i] << " "
				<< Person_Data.StoredLstName[i] << " "
				<< Person_Data.StoredCNIC[i] << " "
				<< Person_Data.StoredNO[i] << " "
				<< Person_Data.StoredPIN[i] << " "
				<< Person_Data.StoredCity[i] << " "
				<< Person_Data.StoredMail[i] << " "
				<< Person_Data.gender[i] << "\n";
		}
		SaveDataForTransferFunds.close();
	}
	void AccountINFO()
	{
		cout << "\n\n\t\t\t  Account Details";
		ifstream Search;

		string FindID = Person_Data.AccountNumber;
		system("cls");
		Search.open("UserInfo.txt");
		cout << "*_ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ Account Holder Infomation & Detail_ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _*";
		for (int i = 0; i < 10; i++)
		{
			while (Search >> Person_Data.StoredAccountNO[i] >> Person_Data.StoredAmount[i] >> Person_Data.StoredFrstName[i] >> Person_Data.StoredLstName[i] >> Person_Data.StoredCNIC[i] >> Person_Data.StoredNO[i] >> Person_Data.StoredPIN[i] >> Person_Data.StoredCity[i] >> Person_Data.StoredMail[i] >> Person_Data.gender[i])

				if (FindID == Person_Data.StoredAccountNO[i])
				{
					cout << "\n\n\t\t\t  Bank Account Number : " << Person_Data.StoredAccountNO[i] << endl;
					cout << "\n\n\t\t\t  Please type Admin Personal Identification Number(PIN) : " << Person_Data.StoredPIN[i] << endl;
					cout << "\n\n\t\t\t  Account Holder Name : " << Person_Data.StoredFrstName[i] << " " << Person_Data.StoredLstName[i] << endl;
					cout << "\n\n\t\t\t  Holder NIC : " << Person_Data.StoredCNIC[i] << endl;
					cout << "\n\n\t\t\t  Phone# " << Person_Data.StoredNO[i] << endl;
					cout << "\n\n\t\t\t  Balance : " << Person_Data.StoredAmount[i] << endl;
					cout << "\n\n\t\t\t  Address : " << Person_Data.StoredCity[i] << endl;
					cout << "\n\n\t\t\t  Mail : " << Person_Data.StoredMail[i] << endl;
					cout << "\n\n\t\t\t  Gender : " << (Person_Data.gender[i] == 1 ? "Male" : "Female") << endl;

					break;
				}

		}


		Search.close();
	}

	int ChangePIN()
	{
		string FindID = Person_Data.AccountNumber;
		bool accountFound = false;

		fstream InfoEditor;
		InfoEditor.open("UserInfo.txt", ios::in);

		if (!InfoEditor) {
			cout << "\n\n\n\t\t\t  Error opening file." << endl;
			return 1;
		}
		else {
			for (size_t i = 0; i < 10; i++) {
				InfoEditor >> Person_Data.StoredAccountNO[i]
					>> Person_Data.balance[i]
					>> Person_Data.StoredFrstName[i]
					>> Person_Data.StoredLstName[i]
					>> Person_Data.StoredCNIC[i]
					>> Person_Data.StoredNO[i]
					>> Person_Data.StoredPIN[i]
					>> Person_Data.StoredCity[i]
					>> Person_Data.StoredMail[i]
					>> Person_Data.gender[i];

				if (FindID == Person_Data.StoredAccountNO[i]) {
					accountFound = true;
					cout << "\n\n\t\t\t  Enter New Personal Identification Number(PIN) : \n\t\t\t  ";
					cin >> Person_Data.StoredPIN[i];
					cout << "\n\n\t\t\t  Personal Identification Number(PIN) Changed Successfully!";
				}
			}

			InfoEditor.close();

			if (!accountFound) {
				cout << "\n\n\n\t\t\t  No Record Found..." << endl;
				cout << "\n\n\n\t\t\t  Try Again" << endl;
				return 1;
			}

			fstream SavingInfo;
			SavingInfo.open("UserInfo.txt", ios::out);

			if (SavingInfo.is_open()) {
				for (int i = 0; i < 10; i++) {
					SavingInfo << Person_Data.StoredAccountNO[i] << " "
						<< Person_Data.balance[i] << " "
						<< Person_Data.StoredFrstName[i] << " "
						<< Person_Data.StoredLstName[i] << " "
						<< Person_Data.StoredCNIC[i] << " "
						<< Person_Data.StoredNO[i] << " "
						<< Person_Data.StoredPIN[i] << " "
						<< Person_Data.StoredCity[i] << " "
						<< Person_Data.StoredMail[i] << " "
						<< Person_Data.gender[i] << "\n";
				}
				SavingInfo.close();
			}
			else {
				cout << "\n\n\n\t\t\t  Error in Writing Info..." << endl;
				return 1;
			}
		}
		return 0;
	}
	void UpdateINFO()
	{
		bool accountFound = false;
		string FindID = Person_Data.AccountNumber;
		fstream InfoEditor;
		InfoEditor.open("UserInfo.txt", ios::in);

		if (!InfoEditor) {
			cout << "\n\n\n\t\t\t  Error opening file." << endl;
			return;
		}
		else {
			for (size_t i = 0; i < 10; i++) {
				InfoEditor >> Person_Data.StoredAccountNO[i] >> Person_Data.balance[i] >> Person_Data.StoredFrstName[i] >> Person_Data.StoredLstName[i] >> Person_Data.StoredCNIC[i] >> Person_Data.StoredNO[i] >> Person_Data.StoredPIN[i] >> Person_Data.StoredCity[i] >> Person_Data.StoredMail[i] >> Person_Data.gender[i];

				if (FindID == Person_Data.StoredAccountNO[i]) {
					accountFound = true;

					cout << "\n\n\n\t\t\t  Select Info To Change:" << endl;
					cout << "\n\n\n\t\t\t  1. First Name \n\n\n\t\t\t  2. Second Name \n\n\n\t\t\t  3. Phone No. \n\n\n\t\t\t  4. Address \n\n\n\t\t\t  5. Mail \n\n\n\t\t\t  6. Gender \n\n\n\t\t\t  Your Choice : ";
					int choice;
					choice = GetNumberInput(1);

					switch (choice)
					{
					case 1:
						cout << "\n\n\t\t\t  Enter New First Name : \n\t\t\t  ";
						cin >> Person_Data.StoredFrstName[i];
						cout << "\n\n\t\t\t  First Name Changed Successfully!";
						break;
					case 2:
						cout << "\n\n\t\t\t  Enter New Second Name : \n\t\t\t  ";
						cin >> Person_Data.StoredLstName[i];
						cout << "\n\n\t\t\t  Second Name Changed Successfully!";
						break;
					case 3:
						cout << "\n\n\t\t\t  Enter New Phone No. : \n\t\t\t  ";
						cin >> Person_Data.StoredNO[i];
						cout << "\n\n\t\t\t  Phone No. Changed Successfully!";
						break;
					case 4:
						cout << "\n\n\t\t\t  Address : \n\t\t\t  ";
						cin >> Person_Data.StoredCity[i];
						cout << "\n\n\t\t\t  Address Changed Successfully!";
						break;
					case 5:
						cout << "\n\n\t\t\t  Enter New Mail  : \n\t\t\t  ";
						cin >> Person_Data.StoredMail[i];
						cout << "\n\n\t\t\t  Mail  Changed Successfully!";
						break;
					case 6:
						cout << "\n\n\t\t\t  Enter New Gender (Enter 1 for Male & 0 for Female) : \n\t\t\t  ";
						cin >> Person_Data.gender[i];
						cout << "\n\n\t\t\t  Gender Changed Successfully!";
						break;
					default:
						cout << "\n\n\t\t\t  Invalid Choice. Try Again: \n\t\t\t  ";

						break;
					}
				}
			}

			InfoEditor.close();

			if (!accountFound) {
				cout << "\n\n\n\t\t\t  No Record Found..." << endl;
				cout << "\n\n\n\t\t\t  Try Again" << endl;
				return;
			}

			fstream SavingInfo;
			SavingInfo.open("UserInfo.txt", ios::out);

			if (SavingInfo.is_open()) {
				for (int i = 0; i < 10; i++) {
					SavingInfo << Person_Data.StoredAccountNO[i] << " "
						<< Person_Data.balance[i] << " "
						<< Person_Data.StoredFrstName[i] << " "
						<< Person_Data.StoredLstName[i] << " "
						<< Person_Data.StoredCNIC[i] << " "
						<< Person_Data.StoredNO[i] << " "
						<< Person_Data.StoredPIN[i] << " "
						<< Person_Data.StoredCity[i] << " "
						<< Person_Data.StoredMail[i] << " "
						<< Person_Data.gender[i] << "\n";
				}
				SavingInfo.close();
			}
			else {
				cout << "\n\n\n\t\t\t  Error in Writing Info..." << endl;
				return;
			}
		}
	}


	void GenerateReceipt() {
		fstream Receipt;
		string FindID = Person_Data.AccountNumber;
		system("cls");
		Receipt.open("UserInfo.txt", ios::in);
		cout << "*_ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ Receipt of Transactions _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _*";

		for (int i = 0; i < 10; i++) {
			while (Receipt >> Person_Data.StoredAccountNO[i] >> Person_Data.balance[i] >> Person_Data.StoredFrstName[i] >> Person_Data.StoredLstName[i] >> Person_Data.StoredCNIC[i] >> Person_Data.StoredNO[i] >> Person_Data.StoredPIN[i] >> Person_Data.StoredCity[i] >> Person_Data.StoredMail[i] >> Person_Data.gender[i]) {
				if (FindID == Person_Data.StoredAccountNO[i]) {
					if (Person_Data.transact == 0) {
						cout << "\n\n\t\t\t  No transaction was performed." << endl;
						cout << "\n\n\t\t\t  Press any key to go back...";
						cin.get();
					}
					else {
						cout << "\n\n\t\t\t  Time : "; displayLocalDateTime();
						cout << "\n\n\t\t\t  Bank Account Number : " << Person_Data.StoredAccountNO[i] << endl;
						cout << "\n\n\t\t\t  Account Holder Name : " << Person_Data.StoredFrstName[i] << " " << Person_Data.StoredLstName[i] << endl;
						cout << "\n\n\t\t\t  Transaction of Rs. : " << Person_Data.transact << endl;
						cout << "\n\n\t\t\t  Holder NIC : " << Person_Data.StoredCNIC[i] << endl;
						cout << "\n\n\t\t\t  Phone# " << Person_Data.StoredNO[i] << endl;
						cout << "\n\n\t\t\t  Balance : " << Person_Data.balance[i] << endl;
						cout << "\n\n\t\t\t  Address : " << Person_Data.StoredCity[i] << endl;
						cout << "\n\n\t\t\t  Mail : " << Person_Data.StoredMail[i] << endl;
					}
				}
			}

		}
		cout << "\n\n\t\t\t  Processing Print... \n\n\t\t\t  ";
		system("pause");
		Receipt.close();
	}
};


class UserOperations : public AccountHolder
{
public:

	void CheckHolderPassword() {
		string path = "UserInfo.txt";

		bool loggedIn = false;
		while (!loggedIn)
		{

			design();
			cout << "\n\n\t\t\t  Please type your Bank Account Number : ";
			cin >> Person_Data.AccountNumber;
			cout << "\n\t\t\t  Please type Personal Identification Number(PIN) : ";
			cin >> Person_Data.pin;

			if (Person_Data.AccountNumber == "admin" && Person_Data.pin == "exit")
			{
				cout << "\n\n\t\t\t  Exit By ADMIN Command! \n\n\t\t\t  ";
				system("pause");

				exit(0);
			}

			fstream loginFileAH;
			loginFileAH.open(path, ios::in);
			if (!loginFileAH.is_open()) {
				cout << "Error in Opening File..." << endl;
				break;
			}

			string StoredAccountNumber, Stored_pin;
			for (int i = 0; i < 10; i++)
			{
				while (loginFileAH >> Person_Data.StoredAccountNO[i] >> Person_Data.balance[i] >> Person_Data.StoredFrstName[i] >> Person_Data.StoredLstName[i] >> Person_Data.StoredCNIC[i] >> Person_Data.StoredNO[i] >> Person_Data.StoredPIN[i] >> Person_Data.StoredCity[i] >> Person_Data.StoredMail[i] >> Person_Data.gender[i])

					if (Person_Data.AccountNumber == Person_Data.StoredAccountNO[i] && Person_Data.pin == Person_Data.StoredPIN[i]) {
						Operations();
						loggedIn = true;
						break;
					}

			}

			loginFileAH.close();

			if (!loggedIn) {
				cout << "\n\n\n\t\t\t  Invalid User ID or Password...\n\n\t\t\t  ";
				char tryAgain;
				do {
					cout << "\n\n\n\t\t\t  Do you want to Try again : \n\n\n\t\t\t  (Y/N)?";
					cin >> tryAgain;
				} while (tryAgain != 'y' && tryAgain != 'Y' && tryAgain != 'n' && tryAgain != 'N');

				if (tryAgain == 'y' || tryAgain == 'Y') {
					system("cls");
				}
				else {
					cout << "\n\n\n\t\t\t  Thanks for visiting Us :)...\n\n\t\t\t  ";
					exit(0);
				}
			}
		}
	}

	void Operations()
	{

		int Option;
		cout << "\n\n\n\t\t\t  Customer Login Successful!\n\n\t\t\t  ";
		system("pause");
		system("cls");
	Back:
		cout << "\n\n\t\t\t  Welcome User \n\n\t\t\t  Enter your choice : \n\n\t\t\t  1. Fast Cash\n\n\t\t\t  2. Cash Withdrawal\n\n\t\t\t  3. Deposit\n\n\t\t\t  4. Transactions \n\n\t\t\t  5. Account Detail\n\n\t\t\t  6. Change PIN \n\n\t\t\t  7. Update Accound INFO \n\n\t\t\t  8. Generate Receipt\n\n\t\t\t  9. Log out\n\n\t\t\t  Your Choice : ";
		Option = GetNumberInput(1);


		switch (Option)
		{
		case 1:
		{
			cout << "\n\n\t\t\t  Fast Cash";
			QuickCash();
			cout << "\n\n\t\t\t  ";
			system("pause");
			system("cls");
			goto Back;
			break;
		}
		case 2:
			cout << "\n\n\t\t\t  Cash Withdrawal";
			WithDrawalCash();
			cout << "\n\n\t\t\t  ";
			system("pause");
			system("cls");
			goto Back;
			break;
		case 3:
			cout << "\n\n\t\t\t  Deposit";
			Deposit();
			cout << "\n\n\t\t\t  ";
			system("pause");
			system("cls");
			goto Back;
			break;
		case 4:

			TransferAmount();
			cout << "\n\n\t\t\t  ";
			system("pause");
			system("cls");
			goto Back;
			break;
		case 5:
			AccountINFO();
			cout << "\n\n\t\t\t  ";
			system("pause");
			system("cls");
			goto Back;
			break;

		case 6:
			cout << "\n\n\t\t\t  Change Personal Identification Number(PIN)";
			ChangePIN();
			cout << "\n\n\t\t\t  ";
			system("pause");
			system("cls");
			goto Back;
			break;

		case 7:
			UpdateINFO();
			cout << "\n\n\t\t\t  ";
			system("pause");
			system("cls");
			goto Back;
			break;
		case 8:
			GenerateReceipt();
			system("cls");
			goto Back;
			break;
		case 9:
			cout << "\n\n\t\t\t  Logged out\n\n\t\t\t  ";
			system("pause");
			system("cls");
			CheckHolderPassword();
			break;

		default:
			cout << "\n\n\t\t\t  Invalid Choice...\n\n\t\t\t  Try Again...";
			system("pause");
			cout << "\n\n\t\t\t  ";
			system("cls");
			goto Back;
			break;
		}
	}


};

class Administrator : virtual public BANK
{
public:
	UserOperations StartATM;
	AdminData* head;
	Administrator() : head(nullptr) {}

	void ReadFromFile(string csvFile) {
		ifstream File(csvFile);
		if (!File.is_open()) {
			cerr << "Error opening the file." << endl;
			return;
		}

		while (File) {
			AdminData* newPerson = new AdminData();
			ReadPersonDataFromFile(File, newPerson);
			newPerson->next = nullptr;

			if (head == nullptr) {
				head = newPerson;
			}
			else {
				AdminData* temp = head;
				while (temp->next != nullptr) {
					temp = temp->next;
				}

				temp->next = newPerson;
			}
		}

		File.close();
	}

	void ReadPersonDataFromFile(ifstream& infile, AdminData* AdminHead) {
		string line;
		getline(infile, line);
		stringstream ss(line);

		getline(ss, AdminHead->StoredAccountNO, ',');
		ss >> AdminHead->StoredPIN;
		string AdminID, AdminPin;

		bool loggedIn = false;
		while (!loggedIn) {
			cout << "\n\n\t\t\t  Please type Admin Bank ID : ";
			cin >> AdminID;
			cout << "\n\t\t\t  Please type Admin Personal Identification Number(PIN) : ";
			cin >> AdminPin;



			string StoredUserID, Stored_pin;
			if (AdminID == AdminHead->StoredAccountNO && AdminPin == AdminHead->StoredPIN) {
				AdminOperation();
				loggedIn = true;
				break;
			}



			if (!loggedIn) {
				cout << "\n\n\n\t\t\t  Invalid User ID or Password...\n\n\t\t\t  ";
				char tryAgain;
				do {
					cout << "\n\n\n\t\t\t  Do you want to Try again : \n\n\n\t\t\t  (Y/N)?";
					cin >> tryAgain;
				} while (tryAgain != 'y' && tryAgain != 'Y' && tryAgain != 'n' && tryAgain != 'N');

				if (tryAgain == 'y' || tryAgain == 'Y') {
					system("cls");
				}
				else {
					cout << "\n\n\n\t\t\t  Thanks for visiting Us :)...\n\n\t\t\t  ";
					exit(0);
				}
			}
		}
	}
	void AdminPasswordChecker() {
		ReadFromFile("AdminData.txt");

	}
	void AdminOperation()
	{
		cout << "\n\n\n\t\t\t  Admin Login Successful!\n\n\t\t\t  ";
		system("pause");
		system("cls");
	Back:
		cout << "\n\n\t\t\t  Welcome Administrator\n\n\t\t\t  Please select your choice : \n\n\t\t\t  1. Search User Detail \n\n\t\t\t  2. ATM INFO \n\n\t\t\t  3. Start ATM\n\n\t\t\t  4. Turn OFF the System \n\n\t\t\t  Your Choice : ";
		int admin_choice;
		admin_choice = GetNumberInput(1);

		switch (admin_choice)
		{
		case 1:
		{
			system("cls");
			cout << "\n\n\t\t\t  Account Details";
			fstream Search;
			bool recordFound = false;
			string FindID;
			cout << "\n\n\t\t\t  Enter Account Number you want to find Details : \n\n\t\t\t  ";
			cin >> FindID;
			system("cls");
			Search.open("UserInfo.txt");
			cout << "*_ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ Account Holder Infomation & Detail_ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _*";
			for (int i = 0; i < 10; i++)
			{
				while (Search >> Person_Data.StoredAccountNO[i] >> Person_Data.StoredAmount[i] >> Person_Data.StoredFrstName[i] >> Person_Data.StoredLstName[i] >> Person_Data.StoredCNIC[i] >> Person_Data.StoredNO[i] >> Person_Data.StoredPIN[i] >> Person_Data.StoredCity[i] >> Person_Data.StoredMail[i] >> Person_Data.gender[i])

					if (FindID == Person_Data.StoredAccountNO[i])
					{
						recordFound = true;
						cout << "\n\n\t\t\t  Bank Account Number : " << Person_Data.StoredAccountNO[i] << endl;
						cout << "\n\n\t\t\t  Please type Admin Personal Identification Number(PIN) : " << Person_Data.StoredPIN[i] << endl;
						cout << "\n\n\t\t\t  Account Holder Name : " << Person_Data.StoredFrstName[i] << " " << Person_Data.StoredLstName[i] << endl;
						cout << "\n\n\t\t\t  Holder NIC : " << Person_Data.StoredCNIC[i] << endl;
						cout << "\n\n\t\t\t  Phone# " << Person_Data.StoredNO[i] << endl;
						cout << "\n\n\t\t\t  Balance : " << Person_Data.StoredAmount[i] << endl;
						cout << "\n\n\t\t\t  Address : " << Person_Data.StoredCity[i] << endl;
						cout << "\n\n\t\t\t  Mail : " << Person_Data.StoredMail[i] << endl;
						cout << "\n\n\t\t\t  Gender : " << (Person_Data.gender[i] == 1 ? "Male" : "Female") << endl;
						cout << "\n\n\t\t\t  ";
						system("pause");
						system("cls");

						break;
					}

			}
			if (!recordFound) {
				cout << "\n\n\t\t\t  No Record Found...";
				cout << "\n\n\t\t\t  ";
				system("pause");
			}

			Search.close();

			goto Back;
			break;
		}

		case 2:
			system("cls");
			cout << "\n\n\t\t\t  ATM Info:\n";
			cout << "\t\t\t  ----------------------\n";
			cout << "\t\t\t  Location: ABC Bank, Kharian Branch\n";
			cout << "\t\t\t  Model: ABC-1234\n";
			cout << "\t\t\t  Serial No: S12345678\n";
			cout << "\t\t\t  Year: 2023\n";
			cout << "\n\n\t\t\t  End of ATM Info\n\n\n\t\t\t  ";
			system("pause");
			system("cls");
			goto Back;
			break;
		case 3:
			system("cls");
			StartATM.CheckHolderPassword();
			break;
		case 4:
			system("cls");
			cout << "\n\n\t\t\t  Good Bye Admin...\n\n\t\t\t  Have a Nice Day :)\n\n\t\t\t  ";
			system("pause");
			exit(0);
			break;


		default:
			cout << "Invalid Choice...";
			system("pause");
			cout << "\n\n\t\t\t  ";
			system("cls");
			goto Back;
			break;
		}

	}

};



class ManageUsers
{
public:

	Administrator Admin;
	UserOperations Account;
	void HomeScreenMenu()
	{

		design();
		cout << "\n\n\n\t\t\t  Please INSERT your Card [Press any Key to insert card]\n\n\t\t\t  ";
		system("pause");
		system("cls");

		char choice;
		do {
			design();
			cout << "\n\n\n\t\t\t  Login as : \n\n\n\n\t\t\t  1. Administrator\n\n\t\t\t  2. Account Holder\n\n\t\t\t  3.Exit\n\n\t\t\t  Your choice : ";
			choice = GetNumberInput(1);

			switch (choice) {
			case 1:
				system("cls");
				Admin.AdminPasswordChecker();
				break;
			case 2:
				system("cls");
				Account.CheckHolderPassword();
				break;
			case 3:
				system("cls");
				cout << "\n\n\t\t\t  Thanks for visiting us :)" << endl;
				return;
				break;
			default:
				cout << "\n\n\n\t\t\t  Invalid Choice " << endl;
				char tryAgain;
				do {
					cout << "\n\n\n\t\t\t  Do you want to Try again : \n\n\n\t\t\t  (Y/N)?";
					cin >> tryAgain;
				} while (tryAgain != 'y' && tryAgain != 'Y' && tryAgain != 'n' && tryAgain != 'N');

				if (tryAgain == 'y' || tryAgain == 'Y') {
					system("cls");
				}
				else {
					cout << "\n\n\n\t\t\t  Thanks for visiting Us :)...\n\n\t\t\t  ";
					exit(0);
				}
			}
		} while (choice != '1' && choice != '2' && choice != '3');

	}

};

int main()
{
	cout << ANSI_WHITE_BG << ANSI_BLUE;
	system("cls");

	BANK bankObject;
	bankObject.displayLocalDateTime();

	ManageUsers userManager;
	ManageUsers* userManagerPointer = &userManager;

	userManagerPointer->HomeScreenMenu();


	cout << ANSI_RESET << ANSI_WHITE_BG << ANSI_RED;
	return 0;
}
