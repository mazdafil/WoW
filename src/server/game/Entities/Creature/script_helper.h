/*
* Copyright (C) 2011-2017 ArkCORE <http://www.arkania.net/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
* 
*/

#ifndef DEF_SCRIPT_HELPERS_H_
#define DEF_SCRIPT_HELPERS_H_

enum Events
{
    EVENT_ANIMATION_SUBJECT = 101,
    EVENT_ATTACK_SPELL,
    EVENT_BALLON_MESSAGE,
    EVENT_BEGIN_FLYING,
    EVENT_BEGIN_LANDING,
    EVENT_CAST_COOLDOWN,
    EVENT_CAST_COOLDOWN_01,
    EVENT_CAST_COOLDOWN_02,
    EVENT_CAST_COOLDOWN_03,
    EVENT_CAST_COOLDOWN_04,
    EVENT_CAST_SPELL_00,
    EVENT_CAST_SPELL_01,
    EVENT_CHECK_BOAT,
    EVENT_CHECK_FIGHT,
    EVENT_CHECK_FIRE,
    EVENT_CHECK_FOLLOWING,
    EVENT_CHECK_FOR_CREATURE,
    EVENT_CHECK_FOR_PLAYER,
    EVENT_CHECK_PLAYER,
    EVENT_CHECK_PLAYER_NEAR,
    EVENT_CHECK_POSITION,
    EVENT_CHECK_START_PARTY,
    EVENT_CHECK_TIMEOUT,
    EVENT_COMBAT_STOP,
    EVENT_COOLDOWN_00,
    EVENT_COOLDOWN_01,
    EVENT_COOLDOWN_PLAYER_NEAR,
    EVENT_CREATE_WARRIER,
    EVENT_DELIVER_PACKET,
    EVENT_DESPAWN,
    EVENT_EARTHQUAKE,
    EVENT_ENTER_CAR,
    EVENT_ENTER_VEHICLE,
    EVENT_EXIT_CAR,
    EVENT_EXIT_VEHICLE,
    EVENT_FIGHT_PART_00,
    EVENT_FIGHT_PART_01,
    EVENT_FIGHT_PART_02,
    EVENT_FIGHT_PART_03,
    EVENT_FIND_TARGET,
    EVENT_FINISH,
    EVENT_GIVE_UP,
    EVENT_INVISIBLE_OBJECT,
	EVENT_INIT_TARGET,
    EVENT_KILL_TARGET,
    EVENT_MASTER_RESET,
    EVENT_MOVE_ATTACK,
    EVENT_MOVE_HOME,
    EVENT_MOVE_PART1,
    EVENT_MOVE_PART2,
    EVENT_MOVE_PART3,
    EVENT_MOVE_PART4,
    EVENT_MOVE_PART5,
    EVENT_MOVE_PART6,
    EVENT_MOVE_PART7,
    EVENT_MUSIC_PERIODIC,
    EVENT_PACKET_EXPLODE,
    EVENT_PERIODIC_CHEERING,
    EVENT_PARTY_COOLDOWN,
    EVENT_PLAY_COOLDOWN,
    EVENT_PLAY_PERIODIC_SOUND,
    EVENT_PLAY_PERIODIC_EMOTE,
    EVENT_PLAY_SOUND1,
    EVENT_PLAY_SOUND2,
    EVENT_PLAYING,
    EVENT_PLAYER_EXIT,
    EVENT_RANDOM_EMOTE,
    EVENT_RANDOM_CAST,
    EVENT_RESET_TARGET,
    EVENT_RUN_AWAY,
    EVENT_SAY_HAVE_UNDERSTAND,
    EVENT_SAY_OUTCH,
    EVENT_SAY_THANKS,
    EVENT_SHOOT_ON_DUMMY,
    EVENT_SHOW_FIGHT,
    EVENT_SPAWN_OBJECT,
    EVENT_SPELLCAST,
    EVENT_START_ANIMATION_PACKET,
    EVENT_START_FIGHT,
    EVENT_START_FLY,
    EVENT_START_FLYING,
    EVENT_START_FOLLOW,
    EVENT_START_PARTY,
    EVENT_START_PLAY,
    EVENT_START_PLAY_GAME,
    EVENT_START_RESCUE_LIVE,
    EVENT_START_TALK,
    EVENT_START_WALK,
    EVENT_SUMMON_DEATHWING,
    EVENT_TALK,
    EVENT_TALK_COOLDOWN,
    EVENT_TALK_PART_00,
    EVENT_TALK_PART_01,
    EVENT_TALK_PART_02,
    EVENT_TALK_PART_03,
    EVENT_TALK_PART_04,
    EVENT_TALK_PART_05,
    EVENT_TALK_PART_06,
    EVENT_TALK_PART_07,
    EVENT_TALK_PART_08,
    EVENT_TALK_PART_09,
    EVENT_TALK_PART_10,
    EVENT_TALK_PART_11,
    EVENT_TALK_PART_12,
    EVENT_TALK_PART_13,
    EVENT_TALK_PART_14,
    EVENT_TALK_PART_15,
    EVENT_TALK_PART_16,
    EVENT_TALK_PART_17,
    EVENT_TALK_PART_18,
    EVENT_TALK_PART_19,
    EVENT_TALK_PART_20,
	EVENT_TALK_PART_21,
    EVENT_TALK_PART_22,
    EVENT_TALK_PART_23,
    EVENT_TALK_PART_24,
    EVENT_TALK_PART_25,
    EVENT_TALK_PERIODIC,
    EVENT_TORCH_COOLDOWN,
    EVENT_TRIGGER_TRAP,
    EVENT_WAIT_FOR_NEW_SPEED,
    EVENT_WAIT_TO_MOVE,
    EVENT_WE_ARE_KILLED,

    ACTION_DELIVER_PACKET,
    ACTION_ENTER_CAR,
    ACTION_ERASE,
    ACTION_FOLLOW,
    ACTION_INSERT,
    ACTION_MASTER_KILLED,
    ACTION_RUN_AWAY,
    ACTION_SIZE_OF_LIST,
    ACTION_START_HELP_PLAYER,
    ACTION_START_RESCUE_LIVE,
    ACTION_START_TALK,
    ACTION_STOP_HELP_PLAYER,

    PLAYER_GUID = 99991,
};

// remove randomly, only randomPct is left
class RandomCheck
{
public:
    explicit RandomCheck(float const randomPct) : m_pct(randomPct) { }

    bool operator()(WorldObject* obj) const
    {
        return (frand(0, 100) > m_pct);
    }

private:
    float const m_pct;
};

class RemoveFromList
 {
 public:
     explicit RemoveFromList(std::list<uint32> cList, bool RemoveWhenInList, bool RemovePlayer) : m_cList(cList), m_removeWhenInList(RemoveWhenInList), m_removePlayer(RemovePlayer) { }
 
     bool operator()(WorldObject* obj) const
     {
         if (Player* player = obj->ToPlayer())
             return m_removePlayer;
         else if (Creature* npc = obj->ToCreature())
             for (auto entry : m_cList)
                 if (entry == obj->GetEntry())
                     return m_removeWhenInList;
 
         return true;
     }
 
 private:
     std::list<uint32> m_cList;
     bool m_removeWhenInList;
     bool m_removePlayer;
 };

// to filter std::list<*>, the list has a powerfull command .remove_if
// this command step's during all element's of the list and delete all where the operator-function returns true

// until now this it's beta, a small test for some functions



// end beta test area

class FakeAttackMembers
{
public:
    FakeAttackMembers() : m_hasInit(false) {}
    FakeAttackMembers(Creature* me) : m_me(me), m_hasInit(false) {}

    void Initialize(std::list<uint32> allowedSparrList)
    {
        m_allowedSparrList = allowedSparrList;

        m_meleeWeaponId = m_me->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + BASE_ATTACK);
        m_rangedWeaponId = m_me->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + RANGED_ATTACK);

        int8 id = 1;
        EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(m_me->GetEntry(), id);
        if (!m_meleeWeaponId)
            m_meleeWeaponId = einfo->ItemEntry[BASE_ATTACK];
        if (!m_rangedWeaponId)
            m_rangedWeaponId = einfo->ItemEntry[RANGED_ATTACK];

        for (uint8 i = 0; i < CREATURE_MAX_SPELLS; ++i)
            if (m_me->m_spells[i])
            {
                uint32 spellId = m_me->m_spells[i];
                if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId))
                    if (spellInfo->RangeEntry)
                        if (spellInfo->RangeEntry->MaxRangeHostile < 5.0f && spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE)
                            m_meeleeSpellInfo.push_back(spellInfo);
                        else if (spellInfo->RangeEntry->MaxRangeHostile >= 5.0f && spellInfo->DmgClass == SPELL_DAMAGE_CLASS_RANGED)
                            m_rangedSpellInfo.push_back(spellInfo);
            }
		m_nearestGUID = ObjectGuid::Empty;
		m_sparrGUID = ObjectGuid::Empty;
		m_shootGUID = ObjectGuid::Empty;
        std::list<Creature*> cList = m_me->FindAllCreaturesInRange(30.0f);
        float dist = 30.0f;
        for (auto npc : cList)
            if (IsSparringPartner(npc))
            {
                float d = m_me->GetDistance(npc);
                if (d < 5.0f)
                {
                    if (d < dist)
                    {
                        dist = d;
                        m_nearestGUID = npc->GetGUID();
                    }
                    sparrList.push_back(npc->GetGUID());
                }
                else
                    shootList.push_back(npc->GetGUID());
            }
        m_hasInit = true;
    }

    bool IsSparringPartner(Unit* attacker)
    {
        if (Creature* creature = attacker->ToCreature())
        {
            uint32 entry = creature->GetEntry();
                if (m_me->IsWithinLOSInMap(creature))
                    for (auto e : m_allowedSparrList)
                        if (e == entry)
                            return true;
        }

        return false;
    }

    bool IsMeeleAttack()
    {
        return sparrList.size() ? true : false;
    }

    Creature* GetSparringPartner()
    {
        if (m_sparrGUID == ObjectGuid::Empty && m_nearestGUID != ObjectGuid::Empty)
            m_sparrGUID = m_nearestGUID;


        if (!m_sparrGUID)
        {
            std::list<Creature*> cList;
            for (auto npc : sparrList)
                if (Creature* target = ObjectAccessor::GetCreature(*m_me, npc))
                    if (!target->isDead())
                        cList.push_back(target);

            if (cList.size() > 0)
            {
                uint32 rol = urand(0, cList.size() - 1);
                std::list<Creature*>::const_iterator itr = cList.begin();
                std::advance(itr, rol);
                m_sparrGUID = (*itr)->GetGUID();
            }
        }

        if (Creature* creature = ObjectAccessor::GetCreature(*m_me, m_sparrGUID))
            if (!creature->isDead())
                return creature;
		m_sparrGUID = ObjectGuid::Empty;
        return nullptr;
    }

    Creature* GetRangedPartner()
    {
        if (Creature* creature = ObjectAccessor::GetCreature(*m_me, m_shootGUID))
            if (creature->isDead())
               

        if (shootList.size() && m_rangedSpellInfo.size() & m_rangedWeaponId)
        {
            if (!m_shootGUID)
            {
                std::list<Creature*> cList;
                for (auto npc : shootList)
                    if (Creature* target = ObjectAccessor::GetCreature(*m_me, npc))
                        if (!target->isDead())
                            cList.push_back(target);

                if (cList.size() > 0)
                {
                    uint32 rol = urand(0, cList.size() - 1);
                    std::list<Creature*>::const_iterator itr = cList.begin();
                    std::advance(itr, rol);
                    m_shootGUID = (*itr)->GetGUID();
                }
            }

            if (Creature* creature = ObjectAccessor::GetCreature(*m_me, m_shootGUID))
                if (!creature->isDead())
                    return creature;
        }
		m_shootGUID = ObjectGuid::Empty;
        return nullptr;
    }

    uint32 GetRangedSpellId()
    {
        switch (m_rangedSpellInfo.size())
        {
        case 0:
            return 0;
        default:
            uint32 rol = urand(0, m_rangedSpellInfo.size() - 1);
            std::list<const SpellInfo*>::const_iterator itr = m_rangedSpellInfo.begin();
            std::advance(itr, rol);
            return (*itr)->Id;
        }
        return 0;
    }

    bool m_hasInit;
private:
    Creature* m_me;
    std::list<uint32> m_allowedSparrList;
    ObjectGuid   m_nearestGUID;
    ObjectGuid   m_sparrGUID;
    ObjectGuid   m_shootGUID;
    std::list<ObjectGuid> sparrList;
    std::list<ObjectGuid> shootList;
    uint32 m_meleeWeaponId;
    std::list<const SpellInfo*> m_meeleeSpellInfo;
    uint32 m_rangedWeaponId;
    std::list<const SpellInfo*>  m_rangedSpellInfo;
};

#endif
