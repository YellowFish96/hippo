//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "HippoTestApp.h"
#include "HippoApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
HippoTestApp::validParams()
{
  InputParameters params = HippoApp::validParams();
  return params;
}

HippoTestApp::HippoTestApp(InputParameters parameters) : MooseApp(parameters)
{
  HippoTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

HippoTestApp::~HippoTestApp() {}

void
HippoTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  HippoApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"HippoTestApp"});
    Registry::registerActionsTo(af, {"HippoTestApp"});
  }
}

void
HippoTestApp::registerApps()
{
  registerApp(HippoApp);
  registerApp(HippoTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
HippoTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  HippoTestApp::registerAll(f, af, s);
}
extern "C" void
HippoTestApp__registerApps()
{
  HippoTestApp::registerApps();
}
