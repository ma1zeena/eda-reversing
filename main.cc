// Embedded Disassembler
//    by geohot, posixninja, westbaer, pumpkin, and planetbeing
// edited by ma1zeena
// implemented by ma1zeena
//  released under GPLv3, see http://gplv3.fsf.org/
// check ut my other repos

#include "FrontEndConsole.h"
#include "FrontEndServer.h"
#include "FrontEndRest.h"
#include "Core.h"

#include "Controller/ARM/CoreARM.h"     //gotta be
using namespace eda;

int main(int argc, char* argv[]) {
  // create MVC objects
  Bank* bank = new Bank();
  Core* core = new CoreARM(bank); //arch is decided here for now
  //Server* server = new Server(bank);
  //FrontEnd* server = new FrontEnd(bank);
  //FrontEnd* server = new FrontEndServer(bank);
  FrontEnd* server = new FrontEndRest(bank);
  //FrontEnd* console = new FrontEndConsole(bank);

  //FrontEndConsole has the same interface as the server,
  //  except it serves to one user on the console

  // make indirect attachments
  //bank->attach(server);
  server->attach(core);
  server->launch();

  //console->attach(core);
  //console->launch();

  // run application
  core->runLoop(); //this thread hangs out in the Core

  // clean up
  delete core;
  delete server;
  delete bank;
}
