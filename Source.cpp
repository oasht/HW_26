#include <iostream>
#include<iomanip>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
//В контейнере типа vector хранится набор целых чисел.
//Создайте функторы для решения следующих задач :
//1. Поиск минимального значения;
//2. Поиск максимального значения;
//3. Сортировка данных по убыванию;
//4. Сортировка данных по возрастанию;
//5. Увеличение значений в контейнере на заданную кон -
//станту;
//6. Уменьшение значений в контейнере на заданную кон -
//станту;
//7. Удаление элементов из контейнера равных искомому
//значению.
class Student
{
public:
	string FirstName;
	int age;



	Student(string _name, int _age)
	{
		FirstName = _name;
		age = _age;
	}
	void Print()
	{
		cout << setw(15) << FirstName << setw(6) << age << endl;
	}

	void operator()(int val)
	{
		int max_val = 0;
		int i = 0;
		if (val > age) max_val = val;
		if (i == 10)cout << max_val << endl;
		i++;
	}
	int Get_age()
	{
		return age;
	}
};



void Increase(Student& st)
{
	st.age = st.age + 5;
	cout << st.age<<" ";
}

void Reduce(Student& st)
{
	st.age = st.age - 5;
	cout << st.age << " ";
}

bool Erase_student(Student& st)
{
	return st.age < 18;
}
void main()
{
	
	vector<Student>students
	{
		Student("Petr", 15),
		Student("Anton", 20),
		Student("Olga", 23),
		Student("Ivan", 17),
		Student("Maria", 30)
	};
	cout << "The list of students:" << endl<<endl;
	for (auto el : students)
	{
		el.Print();
	}
	
	cout << endl << endl << "1)" << endl;
	
	auto it1 = min_element(students.begin(), students.end(), [](Student& st1, Student& st2) {return st1.Get_age() < st2.Get_age(); });
	cout << endl << "The youngest person in the group is " << it1->Get_age()<< " years old"<<endl<<endl;

	cout  << "2)" << endl;
	auto it2 = max_element(students.begin(), students.end(), [](Student& st1, Student& st2) {return st1.Get_age() < st2.Get_age(); });
	cout << endl<<"The oldest person in the group is "<<it2->Get_age()<<" years old"<<endl<<endl;

	cout  << "3)" << endl<<endl;
	cout << "Descending sort" << endl<<endl;
	sort(students.begin(), students.end(), [](Student& st1, Student& st2) {return st1.Get_age() > st2.Get_age(); });
	for (auto el : students)
	{
		el.Print();
	}
	
	cout <<endl<<  "4)" << endl<<endl;
	cout<< "Ascending sort" << endl << endl;
	sort(students.begin(), students.end(), [](Student& st1, Student& st2) {return st1.Get_age() < st2.Get_age(); });
	for (auto el : students)
	{
		el.Print();
	}

	cout << endl<<"5)" << endl;
	cout << endl<<"Age increased by 5 years:" << endl<<endl;
	for_each(students.begin(), students.end(), Increase);

	cout << endl<<endl<<"6)" << endl;
	cout << endl<<"Age reduced by 5 years:" << endl<<endl;
	for_each(students.begin(), students.end(), Reduce);


	cout  << endl<<endl<<"7)" << endl<<endl;
	cout <<"Students under 18 y.o. removed" << endl<<endl;
	auto res = remove_if(students.begin(), students.end(), Erase_student);
	students.erase(res, students.end());
	for (auto el : students)
	{
		el.Print();
	}
}