#pragma once
#include <vector>
#include <unordered_map>
#include "Event.hpp"
#include "EventListener.hpp"

namespace tester {
	namespace event {

		typedef std::vector<EventListener*> ListenerList;
		typedef std::unordered_map<uint64, ListenerList*> EventMap;

		class EventDispatcher {
			EventMap *m_EventMap;

		public:
			EventDispatcher();

			~EventDispatcher();

			bool Dispatch(Event &event) const;

			void AddListener(EventListener *eventListener, const Event &event);

			bool RemoveListener(const EventListener *eventListener);

		private:
			void CreateEntry(uint64 id, ListenerList *listerList);

			void CreateEntry(const Event &event, ListenerList *listerList);

			ListenerList* GetListenerList(uint64 id) const;

			ListenerList* GetListenerList(const Event &event) const;
		};

	}
}