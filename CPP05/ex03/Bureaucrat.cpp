#include "Bureaucrat.hpp"


// --------------------------- Bureaucrat Functions ----------------------------

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "A default Bureaucrat has beed constructed\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->_grade = grade;
		std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has beed constructed\n";
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has beed destroyed\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const & ref) : _name(ref.getName() + "_copy")
{
	this->_grade = ref.getGrade();
	std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has beed constructed from a copy\n";
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & ref)
{
	this->_grade = ref.getGrade();
	return (*this);
}

void				Bureaucrat::incrementGrade( void )
{
	std::cout << "Incrementing bureaucrat " << _name << "'s grade " << _grade << " by 1\n";
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->_grade--;
	}
}

void				Bureaucrat::decrementGrade( void )
{
	std::cout << "Decrementing bureaucrat " << _name << "'s grade " << _grade << " by 1\n";
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
	{
		this->_grade++;
	}
}


// Getters
const std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int					Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

// Setters
void				Bureaucrat::setGrade( const int new_grade)
{
	this->_grade = new_grade;
	std::cout << "Bureaucrat " << this->_name << "'s grade was set to " << new_grade << std::endl;
}

// << operator overload
std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs)
{
	o << "Bureaucrat " << rhs.getName() << " has a grade " << rhs.getGrade() << std::endl;
	return (o);
}

// ----------------------------------------------------------------------------



// ---------------------- BureaucratException Functions -----------------------

const char* Bureaucrat::Exception::what() const throw()
{
	return ("BureaucratException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Cannot get a grade > 150!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Cannot get a grade < 1!");
};

// -------------------------------- EX01 ---------------------------------

void Bureaucrat::signForm(Form & ref)
{
	try
	{
		ref.be_signed(*this);
		std::cout << "Bureaucrat " << this->_name << " with a grade " << this->_grade << " succesfully signs " << ref << std::endl;
	}
	catch (Form::Exception &e)
	{
		std::cout << "Bureaucrat " << this->_name << " with a grade " << this->_grade << " cannot sign " << ref << " because " << e.what() << std::endl;
	}
}

// -------------------------------- EX02 ---------------------------------

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " sucesfully executed " << form << std::endl;
	}
	catch (Form::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
