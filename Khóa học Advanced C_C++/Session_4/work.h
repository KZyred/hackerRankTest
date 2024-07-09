#ifndef _INCLUDE_WORK_H_
#define _INCLUDE_WORK_H_

#include <memory>
#include <iostream>

class Employee;

class Manager {
public:
	Manager(){
		std::cout << "ctor of Manager\n";
	}
	
	void set_ptr(std::shared_ptr<Employee> t){
		ptr_manager = t;
	}
	
	~Manager(){
		std::cout << "Manager dtor\n";
		ptr_manager.reset();
	}
	std::shared_ptr<Employee> ptr_manager;
};

class Employee {
public:
	Employee(){
		std::cout << "ctor of Employee\n";
	}	
	
	void set_ptr(std::shared_ptr<Manager> m){
		ptr_employee = m;
	}
	
	~Employee(){
		std::cout << "Employee dtor\n";
		ptr_employee.reset();
	}
	
	std::shared_ptr<Manager> ptr_employee;
};
#endif //_INCLUDE_WORK_H_


