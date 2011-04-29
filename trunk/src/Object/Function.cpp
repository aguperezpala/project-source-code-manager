#include "Function.h"


/* Constructor para setear todo de una */
Function::Function(int completed, int weight, bool tested,
		const std::string &name, const std::string &signature) :
		IObject(IObject::TYPE_FUNCTION),
		mCompleted(completed),
		mWeight(weight),
		mTested(tested),
		mName(name),
		mSignature(signature)
{
	// do nothing
}



/* debug */
void Function::Print(void)
{
	std::cout << "\nFuncion Name " << mName;
	std::cout << "\nFunction completed" << mCompleted;
	std::cout << "\nFunction weight " << mWeight;
	std::cout << "\nFunction Signature: " << mSignature;
	std::cout << std::endl;
}
