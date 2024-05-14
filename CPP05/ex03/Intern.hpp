#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Form;

class Intern
{
	public:
		// Canonic class methods:
		Intern();
		~Intern();
		Intern(Intern const & ref);
		Intern & operator=(Intern const & ref);

		// Subject required method:
		Form *makeForm(std::string form_name, std::string form_target);

		// Exception:
		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif