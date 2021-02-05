#include "HippoApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
HippoApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

HippoApp::HippoApp(InputParameters parameters) : MooseApp(parameters)
{
  HippoApp::registerAll(_factory, _action_factory, _syntax);
}

HippoApp::~HippoApp() {}

void
HippoApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"HippoApp"});
  Registry::registerActionsTo(af, {"HippoApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
HippoApp::registerApps()
{
  registerApp(HippoApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
HippoApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  HippoApp::registerAll(f, af, s);
}
extern "C" void
HippoApp__registerApps()
{
  HippoApp::registerApps();
}
