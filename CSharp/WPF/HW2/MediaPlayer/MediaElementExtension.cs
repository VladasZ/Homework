﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace MediaPlayer
{
    static class MediaElementExtension
    {
        public static int ProgressPercentage(this MediaElement mediaElement)
        {
            return (int)(mediaElement.Position.TotalSeconds / (double)mediaElement.NaturalDuration.TimeSpan.TotalSeconds * 100);
        }

        public static void SetProgress(this MediaElement mediaElement, int percent)
        {
            mediaElement.Position = TimeSpan.FromSeconds(mediaElement.NaturalDuration.TimeSpan.TotalSeconds * ((double)percent / 100));
        }
    }
}
