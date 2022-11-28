#include "sstacApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
sstacApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

sstacApp::sstacApp(InputParameters parameters) : MooseApp(parameters)
{
  sstacApp::registerAll(_factory, _action_factory, _syntax);
}

sstacApp::~sstacApp() {}

void
sstacApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"sstacApp"});
  Registry::registerActionsTo(af, {"sstacApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
sstacApp::registerApps()
{
  registerApp(sstacApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
sstacApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sstacApp::registerAll(f, af, s);
}
extern "C" void
sstacApp__registerApps()
{
  sstacApp::registerApps();
}
