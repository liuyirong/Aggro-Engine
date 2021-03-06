#pragma once

#include "Scene.hpp"
#include "SceneNodeTreeItem.hpp"
#include "EngineContext.hpp"
#include "StaticObjectRenderComponent.hpp"
#include <QDockWidget>
#include <memory>
using namespace std;

/**
* Scene graph viewer.
*
* author: wcrane
* since: 2016-08-28
**/
class SceneGraphTree : public QDockWidget
{
private:
	shared_ptr<QTreeWidget> m_treeWidget;
	shared_ptr<EngineContext> m_context;
	QAction *m_addCubeAction;
	QAction *m_addSphereAction;
	QAction *m_deleteAction;

	bool m_isRefreshing;
	boost::unordered_map<SceneNode *, QTreeWidgetItem *> m_currentNodes;

	void _addSceneNodeRecursive(shared_ptr<SceneNode> node, QTreeWidgetItem *parent, bool isRoot);
	void _addNewNode(shared_ptr<StaticObjectRenderComponent> renderComponent, string name);
	void _selectionChanged();

	void _deleteSelected();

	void _refreshNode(SceneNode *node);
	void _deleteNode(SceneNode *node);
	void _selectNode(SceneNode *node);

public:
	SceneGraphTree(shared_ptr<EngineContext> context, QWidget *parent);

	void refresh(Scene *scene);
};