#include "EventDispatcher.hpp"

namespace tester {
	namespace event {

		EventDispatcher::EventDispatcher() {
			m_EventMap = new EventMap();
		}

		EventDispatcher::~EventDispatcher() {
			for (auto [key, value] : *m_EventMap)
				delete value;
			delete m_EventMap;
		}
		
		bool EventDispatcher::Dispatch(Event &event) const {
			ListenerList *listeners = GetListenerList(event);

			if (listeners == nullptr)
				return false;

			for (EventListener *listener : *listeners) {
				if (listener->OnEvent(event))
					return true;
			}
			return false;
		}

		void EventDispatcher::AddListener(EventListener *eventListener, const Event &event) {
			ListenerList *listeners = GetListenerList(event);

			if (listeners == nullptr) {
				listeners = new ListenerList();
				CreateEntry(event, listeners);
			}

			listeners->push_back(eventListener);
		}

		void EventDispatcher::CreateEntry(uint64 id, ListenerList *listenerList) {
			m_EventMap->emplace(id, listenerList);
		}

		void EventDispatcher::CreateEntry(const Event &event, ListenerList *listenerList) {
			CreateEntry(event.GetID(), listenerList);
		}

		ListenerList* EventDispatcher::GetListenerList(uint64 id) const {
			EventMap::iterator find = m_EventMap->find(id);

			if (find == m_EventMap->end())
				return nullptr;
			return find->second;
		}

		ListenerList* EventDispatcher::GetListenerList(const Event &event) const {
			return (GetListenerList(event.GetID()));
		}
	}
}