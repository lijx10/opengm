//#define GraphicalModelDecomposition BpInference_GraphicalModelDecomposition
#include <boost/python.hpp>
#include <string>
#include "inf_def_visitor.hxx"
#include "marginal_def_visitor.hxx"
#include <opengm/inference/messagepassing/messagepassing.hxx>
#include <param/message_passing_param.hxx>
#include <opengm/operations/logsumexp.hxx>


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
void export_bp(){
   using namespace boost::python;
   wrap_import_array();
   append_subnamespace("solver");

   // setup 
   InfSetup setup;
   setup.cite       =  "";
   setup.algType    =  "message-passing";
   setup.guarantees =  "";
   setup.examples   = ">>> parameter = opengm.InfParam(steps=100,damping=0.5)\n"
                      ">>> inference = opengm.inference.TreeReweightedBp(gm=gm,accumulator='minimizer',parameter=parameter)\n"
                      "\n\n";
   typedef opengm::BeliefPropagationUpdateRules<GM,ACC> UpdateRulesType;
   typedef opengm::MessagePassing<GM, ACC,UpdateRulesType, opengm::MaxDistance> PyBp;
   // export parameter
   exportInfParam<PyBp>("_BeliefPropagation");
   // export inference
   class_< PyBp>("_BeliefPropagation",init<const GM & >())  
   .def(InfSuite<PyBp>(std::string("BeliefPropagation"),setup))
   .def(MarginalSuite<PyBp>())
   ;
}

template void export_bp<opengm::python::GmAdder, opengm::Minimizer>();
template void export_bp<opengm::python::GmAdder, opengm::Maximizer>();
template void export_bp<opengm::python::GmAdder, opengm::Integrator>();
template void export_bp<opengm::python::GmAdder, opengm::Logsumexp>();
template void export_bp<opengm::python::GmMultiplier, opengm::Minimizer>();
template void export_bp<opengm::python::GmMultiplier, opengm::Maximizer>();
template void export_bp<opengm::python::GmMultiplier, opengm::Integrator>();

