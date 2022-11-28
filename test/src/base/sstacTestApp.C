//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "sstacTestApp.h"
#include "sstacApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
sstacTestApp::validParams()
{
  InputParameters params = sstacApp::validParams();
  return params;
}

sstacTestApp::sstacTestApp(InputParameters parameters) : MooseApp(parameters)
{
  sstacTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

sstacTestApp::~sstacTestApp() {}

void
sstacTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  sstacApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"sstacTestApp"});
    Registry::registerActionsTo(af, {"sstacTestApp"});
  }
}

void
sstacTestApp::registerApps()
{
  registerApp(sstacApp);
  registerApp(sstacTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
sstacTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sstacTestApp::registerAll(f, af, s);
}
extern "C" void
sstacTestApp__registerApps()
{
  sstacTestApp::registerApps();
}
