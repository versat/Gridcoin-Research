// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or https://opensource.org/licenses/mit-license.php.
#include "node/ui_interface.h"
#include "init.h"
#include "rpc/server.h"
#include "rpc/client.h"

#include <string>

static int noui_ThreadSafeMessageBox(const std::string& message, const std::string& caption, int style)
{
    LogPrintf("%s: %s", caption, message);
    tfm::format(std::cerr, "%s: %s\n", caption.c_str(), message.c_str());
    return 4;
}

static bool noui_ThreadSafeAskFee(int64_t nFeeRequired, const std::string& strCaption)
{
    return true;
}

static int noui_UpdateMessageBox(const std::string& version, const std::string& message)
{
    std::string caption = _("Gridcoin Update Available");

    LogPrintf("%s:\r\n%s", caption, message);
    tfm::format(std::cerr, "\r\n%s:\r\n%s\r\n%s\r\n", caption.c_str(), version.c_str(), message.c_str());

    return 0;
}

void noui_connect()
{
    // Connect bitcoind signal handlers
    uiInterface.ThreadSafeMessageBox_connect(noui_ThreadSafeMessageBox);
    uiInterface.ThreadSafeAskFee_connect(noui_ThreadSafeAskFee);
    uiInterface.UpdateMessageBox_connect(noui_UpdateMessageBox);
}
