/*
 * author: chengshun.wang@amlogic.com
 * date: 2017-08-04
 * interface api for ctc middleware to ctsplayer
 */

#include "CTC_AmlPlayer.h"
#include <android/log.h>
#include "CTC_MediaProcessor.h"

using namespace android;

#define LOG_TAG "CTC_AmlPlayer"


CTC_AmlPlayer::CTC_AmlPlayer()
{
    ALOGI("CTC_AmlPlayer construct \n");
    m_pTsPlayer = GetMediaProcessor();
}

CTC_AmlPlayer::~CTC_AmlPlayer()
{
    ALOGI("CTC_AmlPlayer destroy\n");
    if (m_pTsPlayer != NULL) {
        delete m_pTsPlayer;
        m_pTsPlayer = NULL;
    }
}

int CTC_AmlPlayer::CTC_GetAmlPlayerVersion()
{
    return 1.0;
}


int CTC_AmlPlayer::CTC_GetPlayMode()
{
    int mode = 0;

    mode = m_pTsPlayer->GetPlayMode();

    return mode;
}

int CTC_AmlPlayer::CTC_SetVideoWindow(int x,int y,int width,int height)
{
    int ret = OK;

    ret = m_pTsPlayer->SetVideoWindow(x, y, width, height);

    return ret;
}

void CTC_AmlPlayer::CTC_GetVideoPixels(int& width, int& height)
{
    m_pTsPlayer->GetVideoPixels(width, height);
}

bool CTC_AmlPlayer::CTC_IsSoftFit()
{
    bool b_ret = false;

    b_ret = m_pTsPlayer->IsSoftFit();

    return b_ret;
}

void CTC_AmlPlayer::CTC_SetSurface(Surface* pSurface)
{
    m_pTsPlayer->SetSurface(pSurface);
}

int CTC_AmlPlayer::CTC_SetEPGSize(int w, int h)
{
    int ret = OK;

    m_pTsPlayer->SetEPGSize(w, h);

    return ret;
}

int CTC_AmlPlayer::CTC_VideoShow()
{
    int ret = OK;

    ret = m_pTsPlayer->VideoShow();

    return ret;
}

int CTC_AmlPlayer::CTC_VideoHide()
{
    int ret = OK;

    ret = m_pTsPlayer->VideoHide();

    return ret;
}

int CTC_AmlPlayer::CTC_StartPlay()
{
    int ret = OK;

    ret = m_pTsPlayer->StartPlay();

    return ret;
}

int CTC_AmlPlayer::CTC_Pause()
{
    int ret = OK;

    ret = m_pTsPlayer->Pause();

    return ret;
}

int CTC_AmlPlayer::CTC_Resume()
{
    int ret = OK;

    ret = m_pTsPlayer->Resume();

    return ret;
}

int CTC_AmlPlayer::CTC_Fast()
{
    int ret = OK;

    ret = m_pTsPlayer->Fast();

    return ret;
}

int CTC_AmlPlayer::CTC_StopFast()
{
    int ret = OK;

    ret = m_pTsPlayer->StopFast();

    return ret;
}

int CTC_AmlPlayer::CTC_Stop()
{
    int ret = OK;

    ret = m_pTsPlayer->Stop();

    return ret;
}

int CTC_AmlPlayer::CTC_Seek()
{
    int ret = OK;

    ret = m_pTsPlayer->Seek();

    return ret;

}

int CTC_AmlPlayer::CTC_WriteData(unsigned char* pBuffer, unsigned int nSize)
{
    int ret = OK;

    ret = m_pTsPlayer->WriteData(pBuffer, nSize);

    return ret;

}

int CTC_AmlPlayer::SoftWriteData(int type, uint8_t *pBuffer, uint32_t nSize, uint64_t timestamp)
{
    int ret = OK;

    PLAYER_STREAMTYPE_E mtype = (PLAYER_STREAMTYPE_E)type;

    ret = m_pTsPlayer->SoftWriteData(mtype, pBuffer, nSize, timestamp);

    return ret;

}


int CTC_AmlPlayer::CTC_SetVolume(int volume)
{
    int ret = OK;

    ret = m_pTsPlayer->SetVolume(volume);

    return ret;
}

int CTC_AmlPlayer::CTC_GetVolume()
{
    int volume = 0;

    volume = m_pTsPlayer->GetVolume();

    return volume;
}

int CTC_AmlPlayer::CTC_SetRatio(int nRatio)
{
    int ret = OK;

    ret = m_pTsPlayer->SetRatio(nRatio);

    return ret;
}

int CTC_AmlPlayer::CTC_GetAudioBalance()
{
    int aBalance = 0;

    aBalance = m_pTsPlayer->GetAudioBalance();

    return aBalance;
}

int CTC_AmlPlayer::CTC_SetAudioBalance(int nAudioBalance)
{
    int ret = OK;

    ret = m_pTsPlayer->SetAudioBalance(nAudioBalance);

    return ret;
}

int CTC_AmlPlayer::CTC_GetCurrentPlayTime()
{
    int time = 0;

    time = m_pTsPlayer->GetCurrentPlayTime();

    return time;
}

int CTC_AmlPlayer::CTC_SwitchSubtitle(int pid)
{
    int ret = OK;

    m_pTsPlayer->SwitchSubtitle(pid);

    return ret;
}

int CTC_AmlPlayer::CTC_SwitchAudio(int pid)
{
    int ret = OK;

    m_pTsPlayer->SwitchAudioTrack(pid);

    return ret;
}

int CTC_AmlPlayer::CTC_InitVideo(void *para)
{
    int ret = OK;

    PVIDEO_PARA_T pVideoPara = (VIDEO_PARA_T*)para;
    ALOGI("CTC_InitVideo: pVideoPara=%p,para=%p, pVideoPara->pid=%d,vfmt=%d, height=%d\n",
        pVideoPara, para, pVideoPara->pid, pVideoPara->vFmt, pVideoPara->nVideoHeight);

    m_pTsPlayer->InitVideo(pVideoPara);

    return ret;
}

int CTC_AmlPlayer::CTC_InitAudio(void *para)
{
    int ret = OK;

    PAUDIO_PARA_T pAudioPara = (AUDIO_PARA_T*)para;

    ALOGI("CTC_InitAudio: pAudioPara=%p,para=%p, pAudioPara->pid=%d, channels=%d\n", pAudioPara, para, pAudioPara->pid, pAudioPara->nChannels);

    m_pTsPlayer->InitAudio(pAudioPara);

    return ret;
}

int CTC_AmlPlayer::CTC_InitSubtitle(void *para)
{
    int ret = OK;

    PSUBTITLE_PARA_T pSubPara = (SUBTITLE_PARA_T*)para;
    m_pTsPlayer->InitSubtitle(pSubPara);

    return ret;
}
