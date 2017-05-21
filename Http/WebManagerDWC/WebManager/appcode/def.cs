using System;
using System.Collections.Generic;
using System.Web;
using System.IO;

public enum RechargeType
{
    // �������
    rechargeRMB,

    // ɾ���Զ���ͷ��
    delIconCustom,
};


public struct DefCC
{
    // ����鿴ҳ
    public const string ASPX_GAME_DETAIL = "/appaspx/stat/gamedetail/GameDetailViewer.aspx";
    // �ټ�������
    public const string ASPX_GAME_DETAIL_BACCARAT = "/appaspx/stat/gamedetail/GameDetailBaccarat.aspx?index={0}";
    // ţţ����
    public const string ASPX_GAME_DETAIL_COWS = "/appaspx/stat/gamedetail/GameDetailCows.aspx?index={0}";
    // ����������
    public const string ASPX_GAME_DETAIL_CROCODILE = "/appaspx/stat/gamedetail/GameDetailCrocodile.aspx?index={0}";
    // ��������
    public const string ASPX_GAME_DETAIL_DICE = "/appaspx/stat/gamedetail/GameDetailDice.aspx?index={0}";
    // ���㹫԰����
    public const string ASPX_GAME_DETAIL_FISH_PARK = "/appaspx/stat/gamedetail/GameDetailFishPark.aspx?index={0}";
    // �ں�÷������
    public const string ASPX_GAME_DETAIL_SHCD = "/appaspx/stat/gamedetail/GameDetailShcd.aspx?index={0}";

    // �˿�����
    public static string[] s_poker = { "diamond", "club", "spade", "heart" };

    public static string[] s_pokerCows = { "diamond", "club", "heart", "spade" };
    public static string[] s_pokerColorCows = { "����", "÷��", "����", "����" };

    // �������������
    public static string[] s_diceStr = { "��", "С", "����" };

    public static string[] s_isBanker = { "�Ƿ���ׯ:��", "�Ƿ���ׯ:��" };

    // �˿�����ֵ
    public static string[] s_pokerNum = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

    // �ټ��ֵĽ��
    public static string[] s_baccaratResult = { "��", "��", "�ж�", "ׯ��", "ׯ" };

    // �ں�÷�����˿���
    public static string[] s_pokerShcd = { "spade", "heart", "club", "diamond", "joker" };
}
