#pragma once
#include <map>
#include <memory>
#include <string>
#include "Scene/Scene.h"

typedef std::map<std::string, std::shared_ptr<Scene>> SceneMap;