// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� GAME_EXAMPLE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// GAME_SHOWHAND_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�

#ifdef GAME_SHOWHAND_EXPORTS
#define GAME_SHOWHAND_API __declspec(dllexport)
#else
#define GAME_SHOWHAND_API __declspec(dllimport)
#endif

extern "C" {
    GAME_SHOWHAND_API void *get_game_engine();
    GAME_SHOWHAND_API void *get_packet_mgr();
}