//
// $Source$
// $Date$
// $Revision$
//
// DESCRIPTION:
// Dialog for monitoring logit equilibrium computation
//
// This file is part of Gambit
// Copyright (c) 2005, The Gambit Project
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//

#ifndef DLNFGLOGIT_H
#define DLNFGLOGIT_H

#include <wx/process.h>
#include "gamedoc.h"

class gbtLogitMixedList;
class gbtLogitPlotCtrl;

class gbtLogitMixedDialog : public wxDialog {
private:
  gbtGameDocument *m_doc;
  int m_pid;
  wxProcess *m_process;
  gbtLogitMixedList *m_mixedList;
  wxStaticText *m_statusText;
  wxButton *m_stopButton, *m_okButton, *m_saveButton;
  wxTimer m_timer;
  wxString m_output;
  gbtLogitPlotCtrl *m_plot;

  void OnStop(wxCommandEvent &);
  void OnTimer(wxTimerEvent &);
  void OnIdle(wxIdleEvent &);
  void OnEndProcess(wxProcessEvent &);
  void OnSave(wxCommandEvent &);

  void Start(void);

public:
  gbtLogitMixedDialog(wxWindow *p_parent, gbtGameDocument *p_doc);

  DECLARE_EVENT_TABLE()
};

#endif  // DLNFGLOGIT_H
