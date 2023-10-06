
//include HEADERS
//

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm &rhs);
		~RobotomyRequestForm(void);
	
	private:
		std::string	_target;

};

#endif
