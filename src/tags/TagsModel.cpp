/*
 * TagsModel.cpp
 *
 *  Created on: Mar 5, 2012
 *      Author: Simon
 */

#include "TagsModel.h"
#include "TagsView.h"
#include "client/Client.h"
#include "TagsModelException.h"
#include "client/SaveInfo.h"

TagsModel::TagsModel():
	save(NULL)
{
	// TODO Auto-generated constructor stub

}

void TagsModel::SetSave(SaveInfo * save)
{
	this->save = save;
	notifyTagsChanged();
}

SaveInfo * TagsModel::GetSave()
{
	return save;
}

void TagsModel::RemoveTag(std::string tag)
{
	if(save)
	{
		std::vector<std::string> * tags = Client::Ref().RemoveTag(save->GetID(), tag);
		if(tags)
		{
			save->SetTags(std::vector<std::string>(*tags));
			notifyTagsChanged();
			delete tags;
		}
		else
		{
			throw TagsModelException(Client::Ref().GetLastError());
		}
	}
}

void TagsModel::AddTag(std::string tag)
{
	if(save)
	{
		std::vector<std::string> * tags = Client::Ref().AddTag(save->GetID(), tag);
		if(tags)
		{
			save->SetTags(std::vector<std::string>(*tags));
			notifyTagsChanged();
			delete tags;
		}
		else
		{
			throw TagsModelException(Client::Ref().GetLastError());
		}
	}
}

void TagsModel::AddObserver(TagsView * observer)
{
	observers.push_back(observer);
	observer->NotifyTagsChanged(this);
}

void TagsModel::notifyTagsChanged()
{
	for(int i = 0; i < observers.size(); i++)
	{
		observers[i]->NotifyTagsChanged(this);
	}
}

TagsModel::~TagsModel() {
	// TODO Auto-generated destructor stub
}

