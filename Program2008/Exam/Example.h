ref class Example
{
public:
	int int_field;
public:
	Example(int number){
		this->int_field = number;
	}
	[System::ComponentModel::Bindable(true)]
	property int Int_field{
		int get() { return int_field;}
		void set(int value) { int_field = value; }
	}
	void Set(){}
	void Get(){}
};
