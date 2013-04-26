#ifndef DOUBLE_ARGUMENT_HXX_
#define DOUBLE_ARGUMENT_HXX_

#include "argument_base.hxx"

namespace opengm {

namespace interface {

/*********************
 * class definitions *
 *********************/

template <class CONTAINER = std::vector<double> >
class DoubleArgument : public ArgumentBase<double, CONTAINER> {
public:
   DoubleArgument(double& storageIn, const std::string& shortNameIn,
         const std::string& longNameIn, const std::string& descriptionIn,
         bool requiredIn = false);
   DoubleArgument(double& storageIn, const std::string& shortNameIn,
         const std::string& longNameIn, const std::string& descriptionIn,
         double& defaultValueIn);
   DoubleArgument(double& storageIn, const std::string& shortNameIn,
         const std::string& longNameIn, const std::string& descriptionIn,
         bool requiredIn, CONTAINER& permittedValuesIn);
   DoubleArgument(double& storageIn, const std::string& shortNameIn,
         const std::string& longNameIn, const std::string& descriptionIn,
         double& defaultValueIn, CONTAINER& permittedValuesIn);
};

/***********************
 * class documentation *
 ***********************/
//TODO add documentation

/******************
 * implementation *
 ******************/

template <class CONTAINER>
inline DoubleArgument<CONTAINER>::DoubleArgument(double& storageIn, const std::string& shortNameIn,
      const std::string& longNameIn, const std::string& descriptionIn,
      bool requiredIn)
      : ArgumentBase<double, CONTAINER>(storageIn, shortNameIn, longNameIn, descriptionIn, requiredIn) {

}

template <class CONTAINER>
inline DoubleArgument<CONTAINER>::DoubleArgument(double& storageIn, const std::string& shortNameIn,
      const std::string& longNameIn, const std::string& descriptionIn,
      double& defaultValueIn)
      : ArgumentBase<double, CONTAINER>(storageIn, shortNameIn, longNameIn, descriptionIn, defaultValueIn) {

}

template <class CONTAINER>
inline DoubleArgument<CONTAINER>::DoubleArgument(double& storageIn, const std::string& shortNameIn,
      const std::string& longNameIn, const std::string& descriptionIn,
      bool requiredIn, CONTAINER& permittedValuesIn)
      : ArgumentBase<double, CONTAINER>(storageIn, shortNameIn, longNameIn, descriptionIn, requiredIn, permittedValuesIn) {

}

template <class CONTAINER>
inline DoubleArgument<CONTAINER>::DoubleArgument(double& storageIn, const std::string& shortNameIn,
      const std::string& longNameIn, const std::string& descriptionIn,
      double& defaultValueIn, CONTAINER& permittedValuesIn)
      : ArgumentBase<double, CONTAINER>(storageIn, shortNameIn, longNameIn, descriptionIn, defaultValueIn, permittedValuesIn) {

}

} // namespace interface

} // namespace opengm

#endif /* DOUBLE_ARGUMENT_HXX_ */
