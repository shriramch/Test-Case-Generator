# include "Generator.h"
# include "Invalid.h"


// Main function controls UI and calls Generators as required
signed main()
{
	int wrong_count = 0;
	string command;
	cout << "\033[2J\033[1;1H";
	string s1;
	cout << "Welcome to the test case generator toolkit." << '\n';
	cout << "Use the command 'manual' or open manual.txt to open the manual." << '\n';
	cout << "Use the command 'gen' or 'generator' to set test cases. Please refer to the manual if you are unsure about the keywords." << '\n';
	cout << "Please enter 'exit' or 'quit' to exit the application." << '\n';
	cout << "Please enter 'clear' to clear the screen." << '\n' << '\n';
	while(true)
	{
		cout << '\n' << "> ";
		getline(cin, command, '\n');
		if(command == "")
			continue;
		// quit
		if(command[0] == 'q')
		{
			stringstream str(command);
			string s;
			str >> s;
			if(s == "quit")
			{
				if(str >> s1)
				{
					wrong_count++;
					cout << "Invalid command, extra words detected." << '\n';
				}
				cout << "Are you sure you want to quit? (y/n)";
				string choice;
				wrong_count = 0;
				getline(cin, choice);
				if(choice == "y")
				{
					cout << '\n' << '\n';
					break;
				}
			}
			else
			{
				wrong_count++;
				cout << "Illegal command \"" << s << "\": did you mean \"quit\"?" << '\n';
			}
		}
		// exit 
		else if(command[0] == 'e')
		{
			stringstream str(command);
			string s;
			str >> s;
			if(s == "exit")
			{
				if(str >> s1)
				{
					wrong_count++;
					cout << "Invalid command, extra words detected." << '\n';
				}
				cout << "Are you sure you want to quit? (y/n)";
				string choice;
				wrong_count = 0;
				getline(cin, choice);
				if(choice == "y")
				{
					cout << '\n' << '\n';
					break;
				}
			}
			else
			{
				wrong_count++;
				cout << "Illegal command \"" << s << "\": did you mean \"exit\"?" << '\n';
			}
		}
		// generate test case
		else if(command[0] == 'g')
		{
			stringstream str(command);
			string s;
			str >> s;
			if(s != "gen" && s != "generate")
			{
				wrong_count++;
				cout << "Illegal command \"" << s << "\": did you mean: \"gen\"?" << '\n';
			}
			else
			{
				wrong_count = 0;
				try
				{
					cout << "Invoked: generation " << '\n' << '\n' << '\n';
					Generate g1;
					g1.genfunc();
					cout << "Generation completed successfully. " << '\n';
				}
				catch(Invalid &e)
				{
					int ecode = e.retError();
					switch(ecode)
					{
						case 1 :
							cout << "Invalid integer input. Aborted." << '\n';
							break;
						case 2 :
							cout << "Invalid string input. Aborted." << '\n';
							break;
						case 3 :
							cout << "Invalid preset. Aborted." << '\n';
							break;
						case 11 :
							cout << "Invalid constraints. Aborted." << '\n';
							break;
						case 21 :
							cout << "Invalid Distribution key. Aborted." << '\n';
							break;
						case 101 :
							cout << "Invalid characters. Aborted." << '\n';
							break;
						case 201 :
							cout << "Invalid floating point input. Aborted." << '\n';
							break;
						case 1001 :
							cout << "Sizes invalid. Aborted." << '\n';
							break;
						case 2001 :
							cout << "Output generated aborted. Generation completed successfully." << '\n';
							break;
						case -1 :
							cout << "Generation aborted." << '\n';
							break;
					}
				}
			}
		}
		// clear screen
		else if(command[0] == 'c')
		{
			stringstream str(command);
			string s;
			str >> s;
			if(s == "clear")
			{
				if(str >> s)
				{
					if(str >> s1)
					{
						wrong_count++;
						cout << "Invalid command, extra words detected." << '\n';
					}
					else if(s == "screen")
					{
						cout << "\033[2J\033[1;1H";
						wrong_count = 0;
					}
					else
					{
						wrong_count++;
						cout << "Illegal command \"clear " << s <<"\"." << '\n';
					}
				}
				else
				{
					cout << "\033[2J\033[1;1H";
					wrong_count = 0;
				}
			}
			else
			{
				wrong_count++;
				cout << "Illegal command \"" << s << "\": did you mean \"clear\"?" << '\n';
			}
		}
		// open manual
		else if(command[0] == 'm')
		{
			stringstream str(command);
			string s;
			str >> s;
			if(s == "manual")
			{
				if(str >> s1)
				{
					wrong_count++;
					cout << "Invalid command, extra words detected." << '\n';
				}
				cout << "Invoked: manual " << '\n' << '\n' << '\n';
				fstream f1("manual.txt", ios :: in);
				while(true)
				{
					string s1;
					getline(f1, s1, '\n');
					if(f1.eof())
						break;
					cout << s1 << '\n';
					this_thread :: sleep_for(microseconds(10000));
				}
				wrong_count = 0;
			}
			else
			{
				wrong_count++;
				cout << "Illegal command \"" << command << "\": did you mean \"manual\"?" << '\n';
			}
		}
		else
		{
			cout << "Invalid command \"" << command << "\"" << '\n';
			wrong_count++;
		}
		if(wrong_count >= 3)
			cout << "In case you have trouble with commands, open manual.txt or open it here using the command \"manual\"." << '\n';
	}
	cout << "Thank you for using the test case generator toolkit." << '\n' << '\n';
	return 0;
}
