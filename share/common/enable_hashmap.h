#pragma once
#ifdef _DEBUG
#include <map>
#define ENABLE_MAP std::map
#include <set>
#define ENABLE_SET std::set
#else
//Ч�ʱ�map�ߺܶ� �����޷��鿴���� ��������
#include <boost/unordered_map.hpp>
#define ENABLE_MAP boost::unordered_map
#include <boost/unordered_set.hpp>
#define ENABLE_SET boost::unordered_set
#endif

