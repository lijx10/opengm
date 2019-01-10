#include <boost/python.hpp>
#include <string>
#include "inf_def_visitor.hxx"

#include <opengm/inference/gibbs.hxx>
#include <param/gibbs_param.hxx>

#include <opengm/python/opengmpython.hxx>
#include <opengm/python/converter.hxx>
#include <opengm/python/numpyview.hxx>
#include <opengm/python/pythonfunction.hxx>


#if PY_MAJOR_VERSION == 2
static void wrap_import_array() {
    import_array();
}
#else
static void * wrap_import_array() {
    import_array();
}
#endif


template<class GM,class ACC>
void export_gibbs(){
   wrap_import_array(); 
   // Py Inference Types 
   using namespace boost::python;
   wrap_import_array();
   append_subnamespace("solver");

   // setup 
   InfSetup setup;
   setup.cite       =  "";
   setup.algType    =  "sampling";
   setup.guarantees =  "";

   // export parameter
   typedef opengm::Gibbs<GM, ACC>  PyGibbs;
   exportInfParam<PyGibbs>("_Gibbs");
   // export inference
   class_<PyGibbs>("_Gibbs",init<const GM & >())  
   .def(InfSuite<PyGibbs>(std::string("Gibbs"),setup))
   ;
}

template void export_gibbs<opengm::python::GmAdder,opengm::Minimizer>();
//template void export_gibbs<GmAdder,opengm::Maximizer>();
//template void export_gibbs<GmMultiplier,opengm::Minimizer>();
template void export_gibbs<opengm::python::GmMultiplier,opengm::Maximizer>();
