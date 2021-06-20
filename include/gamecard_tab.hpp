/*
 * gamecard_tab.hpp
 *
 * Copyright (c) 2020-2021, DarkMatterCore <pabloacurielz@gmail.com>.
 *
 * This file is part of nxdumptool (https://github.com/DarkMatterCore/nxdumptool).
 *
 * nxdumptool is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * nxdumptool is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#ifndef __GAMECARD_TAB_HPP__
#define __GAMECARD_TAB_HPP__

#include "tasks.hpp"
#include "layered_error_frame.hpp"
#include "focusable_item.hpp"

namespace nxdt::views
{
    /* Instantiate the template for our class. */
    typedef LayeredErrorFrame<nxdt::tasks::GameCardTask, nxdt::tasks::GameCardStatusEvent> GameCardLayeredErrorFrame;
    
    class GameCardTab: public GameCardLayeredErrorFrame
    {
        typedef bool (*GameCardSizeFunc)(u64 *size);
        
        private:
            GameCardStatus gc_status = GameCardStatus_NotInserted;
            
            FocusableTable *properties_table = nullptr;
            brls::TableRow *capacity = nullptr;
            brls::TableRow *total_size = nullptr;
            brls::TableRow *trimmed_size = nullptr;
            brls::TableRow *update_version = nullptr;
            brls::TableRow *lafw_version = nullptr;
            brls::TableRow *sdk_version = nullptr;
            brls::TableRow *compatibility_type = nullptr;
            
            brls::ListItem *dump_card_image = nullptr;
            brls::ListItem *dump_certificate = nullptr;
            brls::ListItem *dump_header = nullptr;
            brls::ListItem *dump_decrypted_cardinfo = nullptr;
            brls::ListItem *dump_initial_data = nullptr;
            brls::ListItem *dump_hfs_partitions = nullptr;
            
            std::string GetFormattedSizeString(GameCardSizeFunc func);
        
        public:
            GameCardTab(nxdt::tasks::GameCardTask *gc_status_task);
    };
}

#endif  /* __GAMECARD_TAB_HPP__ */
