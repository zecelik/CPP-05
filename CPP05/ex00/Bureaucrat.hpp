#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
		// Constructors / destructor / '=' overload
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const & ref);
		Bureaucrat & operator=(Bureaucrat const & ref);

		// Increment / Decrement grade
		void				incrementGrade( void );
		void				decrementGrade( void );

		// Getters
		const std::string	getName( void ) const;
		int					getGrade( void ) const;

		// Setters
		void				setGrade( const int new_grade);

		// Nested Exception classes:
		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooHighException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade; 

};

// << overload
std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);


#endif