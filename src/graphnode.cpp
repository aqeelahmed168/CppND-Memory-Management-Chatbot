#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    //_childEdges.push_back(edge);
    _childEdges.push_back(std::make_unique<GraphEdge>(*edge));
}

//// STUDENT CODE
////
/*void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}*/

void GraphNode::MoveChatbotHere(ChatBot chatBotlocal)
{
    _chatBot = std::move(chatBotlocal);
    _chatBot.SetCurrentNode(this);
}

 
void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    //newNode->MoveChatbotHere(_chatBot);
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
    //delete _chatBot;
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    //return _childEdges[index];

    // get the raw pointer with the given index from a vec of smart_ptr
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}